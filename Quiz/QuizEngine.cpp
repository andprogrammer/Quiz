#include "QuizEngine.h"


QuizEngine::QuizEngine()
{
	createQuestions();
}

void QuizEngine::createQuestions()
{
	questions.push_back(Question{ "W ktorym roku odbyl sie Chrzet Polski?", "966", "996", "960", "969", Question::ANSWEAR::A });
	questions.push_back(Question{ "W ktorym roku Polska przystapila do NATO?", "1998", "1999", "2000", "2001", Question::ANSWEAR::B });
	questions.push_back(Question{ "W ktorym roku uchwalona zostala konstytucja 3 maja?", "1882", "1410", "1791", "1525", Question::ANSWEAR::C });
	questions.push_back(Question{ "W ktorym roku odbyla sie bitwa pod Cedynia?", "756", "1354", "1455", "972", Question::ANSWEAR::D });
}
