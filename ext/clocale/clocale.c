#include <ruby.h>
#include <locale.h>
#include <string.h>

/*
 * Changes or queries the locale for a specific category.
 *
 * @param category [Integer]     one of the constants defined in the CLocale module
 * @param locale   [String, nil] Possible values for `locale`:
 *
 *    <tt>nil</tt>::  query the current setting, does not change the programs locale
 *
 *    <tt>""</tt>::   specifies an implementation defined native environment
 *
 *    <tt>"C"</tt>::  specifies a minimal "portable" locale
 *
 * @return [String] the value associated with the category
 *
 * @raise [RuntimeError] if setting the locale fails
 *
 * Calls the <tt>setlocale()</tt> C library function, see
 * http://pubs.opengroup.org/onlinepubs/009695399/functions/setlocale.html.
 */
static VALUE
lc_setlocale(VALUE self, VALUE category, VALUE locale) {
  const char* loc = NULL;
  int cat = FIX2INT(category);

  if (!NIL_P(locale)) {
    loc = StringValueCStr(locale);
  }
  char* ret = setlocale(cat, loc);

  if (ret == NULL) {
    VALUE sym = rb_funcall(self, rb_intern("lookup_const"), 1, category);

    if (NIL_P(sym)) {
      rb_raise(rb_eRuntimeError, "error calling `setlocale(%d, \"%s\")`", cat, loc);
    } else {
      rb_raise(rb_eRuntimeError, "error calling `setlocale(%" PRIsVALUE ", \"%s\")`", sym, loc);
    }
  } else {
    return rb_str_new2(ret);
  }
}

/*
 * Compares two Strings using the current locale.
 *
 * @param s1 [String]
 * @param s2 [String]
 *
 * @return [Integer] -1, 0, +1 if s1 is less than, equal to, or greater than s2 respectively
 *
 * Calls the <tt>strcoll()</tt> C library function, see
 * http://pubs.opengroup.org/onlinepubs/009695399/functions/strcoll.html.
 */
static VALUE
lc_strcoll(VALUE self, VALUE s1, VALUE s2) {
  int ret = strcoll(StringValueCStr(s1), StringValueCStr(s2));

  // clamp ret to range [-1; 1]
  if (ret < 0) ret = -1;
  if (ret > 0) ret = 1;

  return INT2FIX(ret);
}

/*
 * Transform the given String into a canonical form for char comparison.
 *
 * This is useful for sorting a list using Enumerable#sort_by which does a
 * Schwartzian transform.
 *
 * @param s [String]
 *
 * @return [String] transformed according to the current <tt>LC_COLLATE</tt> locale setting
 *
 * Calls the <tt>strxfrm</tt> C library function, see
 * http://pubs.opengroup.org/onlinepubs/009695399/functions/strxfrm.html.
 */
static VALUE
lc_strxfrm(VALUE self, VALUE str) {
  VALUE ret;
  char* c_str = StringValueCStr(str);
  size_t size = 0;
  char* buf = NULL;

  for (;;) {
    size_t needed = strxfrm(buf, c_str, size);

    if (needed == 0) {
      ret = str;
      break;
    } else if (needed < size) {
      ret = rb_str_new2(buf);
      break;
    } else {
      size = needed + 1;
      buf = realloc(buf, size);

      if (buf == NULL) rb_raise(rb_eNoMemError, "could not allocate %zu bytes", size);
    }
  }

  free(buf);

  return ret;
}

/*
 * Initialize the extension by defining the CLocale module.
 */

void
Init_clocale(void) {
  VALUE module = rb_define_module("CLocale");

#define constant(LC) rb_define_const(module, #LC, INT2FIX(LC))

  /* categories defined by POSIX */
  constant(LC_ALL);
  constant(LC_COLLATE);
  constant(LC_CTYPE);
#  ifdef LC_MESSAGES
  constant(LC_MESSAGES);
#  endif
  constant(LC_MONETARY);
  constant(LC_NUMERIC);
  constant(LC_TIME);

  /* GNU extensions */
#  ifdef LC_ADDRESS
  constant(LC_ADDRESS);
#  endif
#  ifdef LC_IDENTIFICATION
  constant(LC_IDENTIFICATION);
#  endif
#  ifdef LC_MEASUREMENT
  constant(LC_MEASUREMENT);
#  endif
#  ifdef LC_NAME
  constant(LC_NAME);
#  endif
#  ifdef LC_PAPER
  constant(LC_PAPER);
#  endif
#  ifdef LC_TELEPHONE
  constant(LC_TELEPHONE);
#  endif

#undef constant

  rb_define_module_function(module, "setlocale", lc_setlocale, 2);
  rb_define_module_function(module, "strcoll", lc_strcoll, 2);
  rb_define_module_function(module, "strxfrm", lc_strxfrm, 1);
}
