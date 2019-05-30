#include "Score.h"

Score Score_Create(unsigned int total)
{
    Score score = 
    {
        .total = total,
        .score = 0,
    };

    return score;
}

void Score_Add(Score* score, const Score* other)
{
    score->total += other->total;
    score->score += other->score;
}

void Score_Multiply(Score* score, unsigned int value)
{
    score->total *= value;
    score->score *= value;
}