#include "DefaultEvaluateStrategy.h"

bool DefaultEvaluateStrategy::IsCommon(const std::string &word)
{
    return dict.GetLevel(word) >= 3;
}

bool DefaultEvaluateStrategy::IsForgettable(const std::string &word)
{
    WordInfo wi = user.GetCounters(word);
    return (wi.Counters[COUNTER_RETRIVE] + wi.Counters[COUNTER_LEARN] > wi.Counters[COUNTER_PASS]) || (wi.Counters[COUNTER_PASS] * 100 / wi.Counters[COUNTER_TEST] < 20);
}

bool DefaultEvaluateStrategy::IsKnown(const std::string &word)
{
    WordInfo wi = user.GetCounters(word);
    if (wi.Counters[COUNTER_PASS] > 0 && wi.Counters[COUNTER_TEST] == 0)
    {
        throw std::string("assert failed");
    }
    return (wi.Counters[COUNTER_PASS] >= 3) && (wi.Counters[COUNTER_PASS] * 100 / wi.Counters[COUNTER_TEST] > 60);
}