#include "stdafx.h"
#include "CppUnitTest.h"
#include "../BackpackProblem/KnapsackFileInput.h"
#include "../BackpackProblem/Knapsack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BackpackTests
{		
	TEST_CLASS(KnapsackFileInputTests)
	{
	public:
		
		TEST_METHOD(correctInput) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("resources/normal.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(1);
			}
			catch (out_of_range e) {
				Assert::AreNotEqual(e.what(), "Error. Amount of things and knapsack`s size must exist.");
			}
			catch (runtime_error e) {
				Assert::AreNotEqual(e.what(), "Error. Amount of things must be positive.");
			}
			delete things;
		}

		TEST_METHOD(incorrectFileNameTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\firingTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (runtime_error e) {
				Assert::AreEqual(e.what(), "Error. Can`t open the input file.");
			}
			delete things;
		}

		TEST_METHOD(incorrectFirstStringTest){
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\firstStringTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (out_of_range e) {
				Assert::AreEqual(e.what(), "Error. Amount of things and knapsack`s size must exist.");
			}
			delete things;
		}

		TEST_METHOD(incorrectSecondStringTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\secondStringTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (out_of_range e) {
				Assert::AreEqual(e.what(), "Error. Amount of things and knapsack`s size must exist.");
			}
			delete things;
		}

		TEST_METHOD(negativeValueFirstStringTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\firstStringNegativeTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (runtime_error e) {
				Assert::AreEqual(e.what(), "Error. Amount of things must be positive.");
			}
			delete things;
		}

		TEST_METHOD(negativeValueSecondStringTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\secondStringNegativeTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (runtime_error e) {
				Assert::AreEqual(e.what(), "Error. Knapsack`s size must be positive.");
			}
			delete things;
		}

		TEST_METHOD(notTrullyCompleteString0Test) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\notTrullyCompleteTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (runtime_error e) {
				Assert::AreEqual(e.what(), "Error. Not trully complete line. Line 1");
			}
			delete things;
		}

		TEST_METHOD(SubjectConstructionErrorTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\subjectConstructionErrorTest.txt", knapsackSize);//создание списка вещей
				Assert::IsTrue(0);
			}
			catch (out_of_range e) {
				Assert::AreEqual(e.what(), "Error. Subject construction error. Line 1");
			}
			delete things;
		}
	};

	TEST_CLASS(KnapsackTest)
	{
	public:

		TEST_METHOD(correctValueFillTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\normal.txt", knapsackSize);//создание списка вещей
				Knapsack *sack = new Knapsack(knapsackSize);//создание рюкзака
				sack->fill(things);//Заполнение 
				Assert::AreEqual(sack->getValue(), 60);
				delete sack;
			}
			catch (out_of_range e) {
				Assert::AreNotEqual(e.what(), "Error. List of things is empty.");
			}
			delete things;	
		}

		TEST_METHOD(correctWeightFillTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\normal.txt", knapsackSize);//создание списка вещей
				Knapsack *sack = new Knapsack(knapsackSize);//создание рюкзака
				sack->fill(things);//Заполнение рюкзака
				Assert::AreEqual(sack->getWeight(), 9);
				delete sack;
			}
			catch (out_of_range e) {
				Assert::AreNotEqual(e.what(), "Error. List of things is empty.");
			}
			delete things;
		}

		TEST_METHOD(correctListFillTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				things = readThingsInfoFromFile("C:\\Курс_2\\АиСтрД\\BackpackProblem\\BackpackProblem\\resources\\normal.txt", knapsackSize);//создание списка вещей
				Knapsack *sack = new Knapsack(knapsackSize);//создание рюкзака
				sack->fill(things);//Заполнение рюкзака
				List * list = new List();
				list->pushBack(new Thing(3, 20, 3, "bottle of water"));
				for(Iterator *i = sack->getList()->createIterator(); i->hasNext(); i->next())
				Assert::AreEqual(i->current()->getAmount(), list->front()->getAmount());
				delete sack;
			}
			catch (out_of_range e) {
				Assert::AreNotEqual(e.what(), "Error. List of things is empty.");
			}
			delete things;
		}

		TEST_METHOD(exceptionIncorrectListFillTest) {
			List * things = new List();
			int knapsackSize = 0;//размер рюкзака
			try {
				Knapsack *sack = new Knapsack(knapsackSize);//создание рюкзака
				sack->fill(things);//Заполнение рюкзака
			}
			catch (out_of_range e) {
				Assert::AreEqual(e.what(), "Error. List of things is empty.");
			}
			delete things;
		}
	};
}