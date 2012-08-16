#ifndef IDEP_TOKENITER_H_
#define IDEP_TOKENITER_H_

// This component defines 1 fully insulated iterator class:
//   idep_TokenIter: iterate over the tokens in an input stream

#include <istream>
using namespace std;


class idep_TokenIter_i;
class idep_TokenIter {
  public:
    // CREATORS
    idep_TokenIter(std::istream& in);
        // Create a token iterator for the specified stream.  A "token" is
        // either a newline ('\n') or a "word" consisting of a contiguous
        // sequence of non-white-space characters.  The stream object must
        // continue to exist while the iterator is in use.

    ~idep_TokenIter();

    void operator++();
        // Advance to next token (i.e., "word" or newline).  The behavior is
        // undefined if the iteration state is not valid.

    // ACCESSORS
    operator const void *() const;
        // Return non-zero if current token is valid; else 0.

    const char *operator()() const;
        // Return the current token (i.e., "word" or newline).  The behavior
        // is undefined if the iteration state is not valid.

 private:
  idep_TokenIter_i *d_this;

  idep_TokenIter(const idep_TokenIter&);
  idep_TokenIter& operator=(const idep_TokenIter&);
};

#endif  // IDEP_TOKENITER_H_
