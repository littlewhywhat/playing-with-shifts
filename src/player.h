class Player {
  private:
    bool m_OutResult;
    bool m_OutLang;
  protected:
    virtual void preinit(Console & console) const {}
    virtual void compute(Console & console, const Strategy & strat) const {
        if (console.play(strat))
            console.out() << strat << std::endl;
    }
  public:
    Player() : m_OutResult(false), m_OutLang(false) {}
    void play(Console & console) const {
        preinit(console);
        uint64_t strat_bound = (uint64_t) 1 << console.wordlen();
        for (uint64_t strat_val = 0; strat_val < strat_bound; strat_val++) {
            Strategy strat(strat_val, console.wordlen());
            compute(console, strat);
        }
    }

};
