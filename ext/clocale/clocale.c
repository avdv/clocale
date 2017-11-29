#include <ruby.h>
#include <locale.h>
#include <string.h>

static VALUE
lc_setlocale(VALUE self, VALUE category, VALUE locale) {
  const char* loc = NULL;
  int cat = FIX2INT(category);

  if (!NIL_P(locale)) {
    loc = StringValueCStr(locale);
  }
  char* ret = setlocale(cat, loc);

  if (ret == NULL) {
    rb_raise(rb_eRuntimeError, "error calling setlocale(%d, \"%s\")", cat, loc);
  } else {
    return rb_str_new2(ret);
  }
}

static VALUE
lc_strcoll(VALUE self, VALUE s1, VALUE s2) {
  int ret = strcoll(StringValueCStr(s1), StringValueCStr(s2));

  // clamp ret to range [-1; 1]
  if (ret < 0) ret = -1;
  if (ret > 0) ret = 1;

  return INT2FIX(ret);
}

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

      if (buf == NULL) rb_raise(rb_eNoMemError, "could not allocate %u bytes", size);
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
  constant(LC_MESSAGES);
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
