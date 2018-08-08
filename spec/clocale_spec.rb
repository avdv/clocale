require 'clocale'

RSpec.describe CLocale do
  context 'module' do
    %i(LC_ALL LC_COLLATE LC_CTYPE LC_MONETARY LC_NUMERIC LC_TIME).each do |const|
      it "has #{const} constant" do
        expect(subject).to be_const_defined const
      end
    end

    it 'setlocale' do
      expect { subject.setlocale(CLocale::LC_ALL, '') }.not_to raise_error
    end
  end
end
