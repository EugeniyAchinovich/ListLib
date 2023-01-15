#include "pch.h"
#include "CppUnitTest.h"
#include "../ListLib/ListLib.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ListUnitTest
{
	TEST_CLASS(ListUnitTest)
	{
	public:
		
		// тесты на изменение размера списка при добавлениях/удалениях с начала и с конца
		TEST_METHOD(TestMethod_GetSize)
		{
			DLList list;

			Book b0("Война и мир", "Л. Н. Толстой", 2240, 1873);
			Book b1("Преступление и наказание", "Ф. М. Достоевский", 1350, 1866);
			Book b2("Капитанская дочка", "А. С. Пушкин", 988, 1836);

			Assert::AreEqual(list.list_size(), 0);

			list.push_back(b0);
			Assert::AreEqual(list.list_size(), 1);
			Assert::AreNotEqual(list.list_size(), 0);

			list.push_front(b1);
			Assert::AreEqual(list.list_size(), 2);
			Assert::AreNotEqual(list.list_size(), 0);
			
			list.push_front(b2);
			Assert::AreEqual(list.list_size(), 3);
			Assert::AreNotEqual(list.list_size(), 0);

			list.push_back(b2);
			Assert::AreEqual(list.list_size(), 4);
			Assert::AreNotEqual(list.list_size(), 0);

			list.pop_back();
			Assert::AreEqual(list.list_size(), 3);
			Assert::AreNotEqual(list.list_size(), 0);

			list.pop_back();
			list.pop_front();
			list.pop_back();

			Assert::AreEqual(list.list_size(), 0);

			list.pop_front();
			Assert::AreEqual(list.list_size(), 0);
			Assert::AreNotEqual(list.list_size(), -1);
		}

		// тесты: действительно ли в конец списка добавляются объекты типа Book (книги) методом push_back
		TEST_METHOD(TestMethod_PushBack)
		{
            DLList list; 

            Book b0("Война и мир", "Л. Н. Толстой", 2240, 1873);
            Book b1("Преступление и наказание", "Ф. М. Достоевский", 1350, 1866);
            Book b2("Капитанская дочка", "А. С. Пушкин", 988, 1836);

            list.push_back(b0);
			list.push_back(b1);
			list.push_back(b2);

			Assert::IsTrue(b0.GetTittle() == list.GetBookTittle(0));
			Assert::IsTrue(b1.GetTittle() == list.GetBookTittle(1));
			Assert::IsTrue(b2.GetTittle() == list.GetBookTittle(2));

			Assert::IsFalse(b1.GetTittle() == list.GetBookTittle(0));
			Assert::IsFalse(b2.GetTittle() == list.GetBookTittle(0));
		}

		// тесты: действительно ли в начало списка добавляются объекты типа Book (книги) методом push_front
		TEST_METHOD(TestMethod_PushFront)
		{
			DLList list;

			Book b0("Война и мир", "Л. Н. Толстой", 2240, 1873);
			Book b1("Преступление и наказание", "Ф. М. Достоевский", 1350, 1866);
			Book b2("Капитанская дочка", "А. С. Пушкин", 988, 1836);

			list.push_front(b0);
			list.push_front(b1);
			list.push_front(b2);

			Assert::IsTrue(b0.GetTittle() == list.GetBookTittle(2));
			Assert::IsTrue(b1.GetTittle() == list.GetBookTittle(1));
			Assert::IsTrue(b2.GetTittle() == list.GetBookTittle(0));

			Assert::IsFalse(b0.GetTittle() == list.GetBookTittle(0));
			Assert::IsFalse(b1.GetTittle() == list.GetBookTittle(0));
		}

		// тесты: действительно ли с начала списка удаляются объекты типа Book (книги) методом pop_front
		TEST_METHOD(TestMethod_PopFront)
		{
			DLList list;

			Book b0("Война и мир", "Л. Н. Толстой", 2240, 1873);
			Book b1("Преступление и наказание", "Ф. М. Достоевский", 1350, 1866);
			Book b2("Капитанская дочка", "А. С. Пушкин", 988, 1836);

			list.push_front(b0);
			list.push_front(b1);
			list.push_front(b2);

			list.pop_front();
			list.pop_front();

			Assert::IsTrue(b0.GetTittle() == list.GetBookTittle(0));
			Assert::IsTrue(list.GetBookTittle(1) == "");
			Assert::IsTrue(list.GetBookTittle(2) == "");
		}

		// тесты: действительно ли с конца списка удаляются объекты типа Book (книги) методом pop_back
		TEST_METHOD(TestMethod_PopBack)
		{
			DLList list;

			Book b0("Война и мир", "Л. Н. Толстой", 2240, 1873);
			Book b1("Преступление и наказание", "Ф. М. Достоевский", 1350, 1866);
			Book b2("Капитанская дочка", "А. С. Пушкин", 988, 1836);

			list.push_back(b0);
			list.push_back(b1);
			list.push_back(b2);

			list.pop_back();
			list.pop_back();

			Assert::IsTrue(b0.GetTittle() == list.GetBookTittle(0));
			Assert::IsTrue(list.GetBookTittle(1) == "");
			Assert::IsTrue(list.GetBookTittle(2) == "");
		}

		// проверка работы перегруженного оператора [] на примере инициализации новой книги значениями другой книги - уже элемента списка
		TEST_METHOD(TestOperator_SquareBrackets)
		{
			DLList list;

			Book book("Война и мир", "Л. Н. Толстой", 2240, 1873);

			list.push_back(book);

			Book book_new = list[0];

			Assert::IsTrue(book.GetTittle() == book_new.GetTittle());
			Assert::IsFalse(book.GetTittle() ==  "");
		}
	};
}
