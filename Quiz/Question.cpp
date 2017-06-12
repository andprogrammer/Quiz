#include "Question.h"


Question::Question(std::string question, std::string answearA, std::string answearB, std::string answearC, std::string answearD, ANSWEAR properAnswear) :
	question(question), properAnswear(properAnswear)
{
	answears[0] = answearA;
	answears[1] = answearB;
	answears[2] = answearC;
	answears[3] = answearD;
}
