#ifndef WORDDATA_H
#define WORDDATA_H
class WordData {
  public:
    virtual ~WordData() {}
    virtual void add(const std::string & word) = 0;
};
#endif
