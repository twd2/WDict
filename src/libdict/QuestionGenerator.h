#ifndef _QUESTIONGENERATOR_H_
#define _QUESTIONGENERATOR_H_

#include <memory>
#include <random>
#include <vector>
#include <functional>

#include "WordInfo.h"
#include "WordIterator.h"
#include "RandomWordIterator.h"
#include "IDictionary.h"
#include "IQuestionBuilder.h"

class QuestionGenerator
{
protected:
    std::shared_ptr<WordIterator> wrongAnswerIter;
    std::default_random_engine &engine;
    IDictionary &dict;
    WordIterator &iter;
    IQuestionBuilder &qb;
private:
    std::vector<std::function<std::string (const std::string&)> > handlers;
    std::discrete_distribution<size_t> dd;
    
public:
    QuestionGenerator(std::default_random_engine &engine, IDictionary &dict, WordIterator &iter, IQuestionBuilder &qb);
    
    void Begin();
    bool GenerateOne(std::string &out_answer);
    void End();
    
protected:
    std::string genTF(const std::string &word);
    std::string genSelDesc(const std::string &word);
    std::string genSelWord(const std::string &word);
    std::string genInputWord(const std::string &word);
};

#endif // _QUESTIONGENERATOR_H_
