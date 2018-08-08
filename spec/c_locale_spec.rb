require 'clocale'

RSpec.describe CLocale do
  %i[LC_ALL LC_COLLATE LC_CTYPE LC_MONETARY LC_NUMERIC LC_TIME].each do |const|
    it "has #{const} constant" do
      is_expected.to(satisfy { |m| m.const_defined? const })
    end
  end

  it 'can call setlocale' do
    expect { described_class.setlocale(CLocale::LC_ALL, '') }.not_to raise_error
  end

  it 'raises an error with invalid locales' do
    expect { described_class.setlocale(CLocale::LC_COLLATE, 'FOOBAR') }.to raise_error(RuntimeError)
  end
end
