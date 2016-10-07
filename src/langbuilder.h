#ifndef LANGBUILDER_H
#define LANGBUILDER_H

class LangBuilder {
  private:
    std::string i2s(uint64_t val, uint32_t wordlen) const {
        std::string s;
        for (uint32_t i = 0; i < wordlen; i++) {
            s.push_back((val & 1) + '0');
            val >>= 1;
        }
        return s;
    }
  protected:
    virtual bool is_relevant(uint64_t comb, const uint32_t & wordlen) const = 0;
  public:
    virtual ~LangBuilder() {};
    void build(Language & lang) const {
    	uint64_t max_comb = 1 << ((uint64_t) lang.wordlen());
    	for (uint64_t comb = 0; comb < max_comb; comb++) 
            if (is_relevant(comb, lang.wordlen()))
                lang.add(i2s(comb, lang.wordlen()));
    }
 };

#endif
