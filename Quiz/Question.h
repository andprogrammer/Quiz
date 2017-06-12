#pragma once
#include <iostream>


class Question
{
public:
	enum class ANSWEAR { A, B, C, D, NONE };

private:
	std::string question;
	std::string answears[4];
	ANSWEAR properAnswear;

public:
	Question(std::string question, std::string answearA, std::string answearB, std::string answearC, std::string answearD, ANSWEAR properAnswear);

	inline std::string getQuestion() const { return question; }
	inline std::string getAnswear1() const { return answears[0]; }
	inline std::string getAnswear2() const { return answears[1]; }
	inline std::string getAnswear3() const { return answears[2]; }
	inline std::string getAnswear4() const { return answears[3]; }
	inline ANSWEAR getProperAnswear() const { return properAnswear; }
};
