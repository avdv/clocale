# frozen_string_literal: true

# This module defines the `LC_*` constants and locale functions from the linked
# C library of the current Ruby interpreter.
#
# @author Claudio Bley <claudio.bley@gmail.com>
module CLocale
  # Looks up the constant corresponding to the given integer value.
  #
  # @param int [Integer]
  # @return [Symbol,nil] the <tt>LC_*</tt> constant as Symbol if found, nil otherwise
  def self.lookup_const(int)
    CLocale.constants.find { |s| CLocale.const_get(s) == int }
  end
end

require 'clocale/clocale'
