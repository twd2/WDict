#include "QuestionGenerator.h"

QuestionGenerator::QuestionGenerator(std::default_random_engine &engine, IDictionary &dict, WordIterator &iter, IQuestionBuilder &qb)
    : engine(engine), dict(dict), iter(iter), qb(qb)
{
    handlers = {
        std::bind(&QuestionGenerator::genTF, this, std::placeholders::_1),
        std::bind(&QuestionGenerator::genSelDesc, this, std::placeholders::_1),
        std::bind(&QuestionGenerator::genSelWord, this, std::placeholders::_1),
        std::bind(&QuestionGenerator::genInputWord, this, std::placeholders::_1)
    };
}

void QuestionGenerator::Begin()
{
    
}

bool QuestionGenerator::Generate(std::string &out_answer)
{
    if (iter.HaveNext())
    {
        std::string word = iter.Next();
        wrongAnswerIter = std::make_shared<RandomWordIterator>(engine, dict, [=] (const std::string &w)
        {
            return w != word;
        });
        
        out_answer = handlers[dd(engine)](word);
        return true;
    }
    else
    {
        return false;
    }
}

void QuestionGenerator::End()
{
    
}
    
std::string QuestionGenerator::genTF(const std::string &word)
{
    std::uniform_int_distribution<size_t> answerDist(0, 1);
    bool correctAnswer = answerDist(engine);
    
    qb.BeginQuestion("请判断: \n");
    
    std::string descWord;
    
    if (correctAnswer)
    {
        descWord = word;
    }
    else
    {
        descWord = wrongAnswerIter->Next();
    }
    
    WordInfo wi = dict.GetWord(descWord);
    std::uniform_int_distribution<size_t> dist(0, wi.Desc.size() - 1);
    qb.BeginQuestion(word + "有\"" + wi.Desc[dist(engine)] + "\"的意思。");
    
    qb.BeginSelect();
    qb.Option('T', "正确");
    qb.Option('F', "错误");
    qb.EndSelect();
    
    qb.EndQuestion();
    
    return correctAnswer ? "T" : "F";
}

std::string QuestionGenerator::genSelDesc(const std::string &word)
{
    return "";
}

std::string QuestionGenerator::genSelWord(const std::string &word)
{
    return "";
}

std::string QuestionGenerator::genInputWord(const std::string &word)
{
    return "";
}