#pragma once
#include "Question.h"
#include <vector>


class QuizEngine
{
	std::vector<Question> questions;

public:
	QuizEngine();

	void createQuestions();
	std::vector<Question> getQuestions() const { return questions; };
	size_t getNumberOfQuestions() const { return questions.size(); }
};