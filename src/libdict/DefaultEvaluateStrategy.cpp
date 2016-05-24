#include "DefaultEvaluateStrategy.h"

bool DefaultEvaluateStrategy::IsCommon(const std::string &word)
{
    return dict.GetLevel(word) >= 3;
}

bool DefaultEvaluateStrategy::IsForgettable(const std::string &word)
{
    auto c = user.GetCounters(word);
    return (c[COUNTER_RETRIVE] + c[COUNTER_LEARN] > c[COUNTER_PASS]) || ((c[COUNTER_TEST] > 0) && (c[COUNTER_PASS] * 100 / c[COUNTER_TEST] < 20));
}

bool DefaultEvaluateStrategy::IsKnown(const std::string &word)
{
    auto c = user.GetCounters(word);
    if (c[COUNTER_PASS] > 0 && c[COUNTER_TEST] == 0)
    {
        throw std::string("assert failed");
    }
    return (c[COUNTER_PASS] >= 1) && (c[COUNTER_PASS] * 100 / c[COUNTER_TEST] > 60);
}

bool DefaultEvaluateStrategy::IsLearned(const std::string &word)
{
    auto c = user.GetCounters(word);
    return c[COUNTER_LEARN] > 0;
}
