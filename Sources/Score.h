#ifndef _SCORE_H_
#define _SCORE_H_

struct _Score
{
    unsigned int total;
    unsigned int score;
};

typedef struct _Score Score;

Score   Score_Create(unsigned int total);
void    Score_Add(Score* score, const Score* other);
void    Score_Multiply(Score* score, unsigned int value);

#endif