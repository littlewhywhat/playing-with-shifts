class Player {
  protected:
    bool m_OutResult;
    bool m_OutLang;
    virtual void precompute(Console & console) {}
    virtual void compute(Console & console, const Strategy & strat) {
        if (console.play(strat) && m_OutResult)
            console.out() << strat << std::endl;
    }
    virtual void postcompute(Console & console) {}
  public:
    Player() : m_OutResult(false), m_OutLang(false) {}
    void set_out_lang(bool val) {
        m_OutLang = val;
    }
    void set_out_result(bool val) {
        m_OutResult = val;
    }
    void play(Console & console) {
        if (m_OutLang)
            console.out() << "language:" << std::endl
                          << console.lang() << std::endl;
        precompute(console);
        uint64_t strat_bound = (uint64_t) 1 << console.wordlen();
        for (uint64_t strat_val = 0; strat_val < strat_bound; strat_val++) {
            Strategy strat(strat_val, console.wordlen());
            compute(console, strat);
        }
        postcompute(console);
    }

};
