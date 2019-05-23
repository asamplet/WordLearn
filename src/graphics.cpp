#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "WordLearn.h"
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#pragma warning(disable : 4996)
#define n 10

using namespace sf;
using namespace std;

int main();
void MainMenu();
void Menu();
void Vocabulary();
void Learning();
void Voc_enru();
void Voc_ruen();
void Learn_enru();
//void Learn_ruen();
struct d w[n];

RenderWindow window(VideoMode(800, 600), "WordLearn");
int main()
{
	MainMenu();
	return 0;
}

void MainMenu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Image menubackgroung;
	menubackgroung.loadFromFile("C:/Users/DNS-PC/Desktop/image/image2.png");
	Texture backgroungTexture;
	backgroungTexture.loadFromImage(menubackgroung);
	Sprite backgroundsprite;
	backgroundsprite.setTexture(backgroungTexture);

	Font fontmenu;
	fontmenu.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text textmenu("WordLearn", fontmenu, 100);
	textmenu.setColor(Color(255, 239, 213));
	textmenu.setStyle(sf::Text::Bold);
	textmenu.setPosition(130, 210);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed
				&& event.mouseButton.button == sf::Mouse::Left)
			{
				Menu();
				break;
			}

		}

		window.clear();
		window.draw(backgroundsprite);
		window.draw(textmenu);
		window.display();

	}
}

void Menu()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Menu");
	Image menuimage1;
	menuimage1.loadFromFile("C:/Users/DNS-PC/Desktop/image/image2.png");
	Texture menuTexture1;
	menuTexture1.loadFromImage(menuimage1);
	Sprite menusprite1;
	menusprite1.setTexture(menuTexture1);

	sf::RectangleShape rectangle(sf::Vector2f(320, 90));
	rectangle.setOutlineThickness(10);
	rectangle.setOutlineColor(Color(216, 148, 214));
	rectangle.setPosition(240, 160);
	rectangle.setFillColor(Color(198, 126, 195));
	sf::RectangleShape rectangle2(sf::Vector2f(320, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(250, 193, 143));
	rectangle2.setPosition(240, 375);
	rectangle2.setFillColor(Color(250, 169, 99));

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text("Словарь", font, 50);//сам объект текст (не строка)
	text.setColor(Color(255, 239, 213));
	text.setStyle(sf::Text::Bold);
	text.setPosition(300, 170);
	Text text2("Изучение", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(285, 385);

	sf::ConvexShape shadow;

	shadow.setPointCount(4);

	shadow.setPoint(0, sf::Vector2f(230, 150));
	shadow.setPoint(1, sf::Vector2f(240, 160));
	shadow.setPoint(2, sf::Vector2f(240, 250));
	shadow.setPoint(3, sf::Vector2f(230, 260));
	shadow.setFillColor(Color(175, 109, 173));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(560, 160));
	shadow2.setPoint(1, sf::Vector2f(570, 150));
	shadow2.setPoint(2, sf::Vector2f(570, 260));
	shadow2.setPoint(3, sf::Vector2f(560, 250));
	shadow2.setFillColor(Color(175, 109, 173));
	
	sf::ConvexShape shadow3;

	shadow3.setPointCount(4);

	shadow3.setPoint(0, sf::Vector2f(230, 365));
	shadow3.setPoint(1, sf::Vector2f(240, 375));
	shadow3.setPoint(2, sf::Vector2f(240, 465));
	shadow3.setPoint(3, sf::Vector2f(230, 475));
	shadow3.setFillColor(Color(212, 150, 97));

	sf::ConvexShape shadow4;

	shadow4.setPointCount(4);

	shadow4.setPoint(0, sf::Vector2f(560, 375));
	shadow4.setPoint(1, sf::Vector2f(570, 365));
	shadow4.setPoint(2, sf::Vector2f(570, 475));
	shadow4.setPoint(3, sf::Vector2f(560, 465));
	shadow4.setFillColor(Color(212, 150, 97));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (IntRect(240, 160, 320, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Vocabulary();
					return;
				}
			}
			if (IntRect(240, 375, 320, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Learning();
					return;
				}
			}
			window.clear();
			window.draw(menusprite1);
			window.draw(rectangle);
			window.draw(shadow);
			window.draw(shadow2);
			window.draw(rectangle2);
			window.draw(shadow3);
			window.draw(shadow4);
			window.draw(text);
			window.draw(text2);
			window.display();
		}

	}
}

void Vocabulary()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Vocabulary");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/image2.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text("Англо-русский", font, 50);
	text.setColor(Color(255, 239, 213));
	text.setStyle(sf::Text::Bold);
	text.setPosition(210, 170);
	Text text2("Русско-английский", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(160, 385);

	sf::RectangleShape rectangle(sf::Vector2f(520, 90));
	rectangle.setOutlineThickness(10);
	rectangle.setOutlineColor(Color(143, 188, 143));
	rectangle.setPosition(140, 160);
	rectangle.setFillColor(Color(144, 238, 144));
	sf::RectangleShape rectangle2(sf::Vector2f(520, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(143, 188, 143));
	rectangle2.setPosition(140, 375);
	rectangle2.setFillColor(Color(144, 238, 144));

	sf::ConvexShape shadow1;

	shadow1.setPointCount(4);

	shadow1.setPoint(0, sf::Vector2f(130, 150));
	shadow1.setPoint(1, sf::Vector2f(140, 160));
	shadow1.setPoint(2, sf::Vector2f(140, 250));
	shadow1.setPoint(3, sf::Vector2f(130, 260));
	shadow1.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(660, 160));
	shadow2.setPoint(1, sf::Vector2f(670, 150));
	shadow2.setPoint(2, sf::Vector2f(670, 260));
	shadow2.setPoint(3, sf::Vector2f(660, 250));
	shadow2.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow3;

	shadow3.setPointCount(4);

	shadow3.setPoint(0, sf::Vector2f(130, 365));
	shadow3.setPoint(1, sf::Vector2f(140, 375));
	shadow3.setPoint(2, sf::Vector2f(140, 465));
	shadow3.setPoint(3, sf::Vector2f(130, 475));
	shadow3.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow4;

	shadow4.setPointCount(4);

	shadow4.setPoint(0, sf::Vector2f(660, 375));
	shadow4.setPoint(1, sf::Vector2f(670, 365));
	shadow4.setPoint(2, sf::Vector2f(670, 475));
	shadow4.setPoint(3, sf::Vector2f(660, 465));
	shadow4.setFillColor(Color(125, 158, 125));

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (IntRect(140, 160, 520, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Voc_enru();
				}
			}
			if (IntRect(140, 375, 520, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Voc_ruen();
				}
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
			{
				Menu();
				return;
			}

			window.clear();
			window.draw(menusprite);
			window.draw(rectangle);
			window.draw(text);
			window.draw(shadow1);
			window.draw(shadow2);
			window.draw(rectangle2);
			window.draw(text2);
			window.draw(shadow3);
			window.draw(shadow4);
			window.display();
		}
	}

}

void Learning()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Learning");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/image2.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);
	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text("Англо-русский", font, 50);
	text.setColor(Color(255, 239, 213));
	text.setStyle(sf::Text::Bold);
	text.setPosition(210, 170);
	Text text2("Русско-английский", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(160, 385);

	sf::RectangleShape rectangle(sf::Vector2f(520, 90));
	rectangle.setOutlineThickness(10);
	rectangle.setOutlineColor(Color(143, 188, 143));
	rectangle.setPosition(140, 160);
	rectangle.setFillColor(Color(144, 238, 144));
	sf::RectangleShape rectangle2(sf::Vector2f(520, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(143, 188, 143));
	rectangle2.setPosition(140, 375);
	rectangle2.setFillColor(Color(144, 238, 144));

	sf::ConvexShape shadow1;

	shadow1.setPointCount(4);

	shadow1.setPoint(0, sf::Vector2f(130, 150));
	shadow1.setPoint(1, sf::Vector2f(140, 160));
	shadow1.setPoint(2, sf::Vector2f(140, 250));
	shadow1.setPoint(3, sf::Vector2f(130, 260));
	shadow1.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(660, 160));
	shadow2.setPoint(1, sf::Vector2f(670, 150));
	shadow2.setPoint(2, sf::Vector2f(670, 260));
	shadow2.setPoint(3, sf::Vector2f(660, 250));
	shadow2.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow3;

	shadow3.setPointCount(4);

	shadow3.setPoint(0, sf::Vector2f(130, 365));
	shadow3.setPoint(1, sf::Vector2f(140, 375));
	shadow3.setPoint(2, sf::Vector2f(140, 465));
	shadow3.setPoint(3, sf::Vector2f(130, 475));
	shadow3.setFillColor(Color(125, 158, 125));

	sf::ConvexShape shadow4;

	shadow4.setPointCount(4);

	shadow4.setPoint(0, sf::Vector2f(660, 375));
	shadow4.setPoint(1, sf::Vector2f(670, 365));
	shadow4.setPoint(2, sf::Vector2f(670, 475));
	shadow4.setPoint(3, sf::Vector2f(660, 465));
	shadow4.setFillColor(Color(125, 158, 125));

	//struct d w[n];
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (IntRect(140, 160, 520, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Learn_enru();
				}
			}
			if (IntRect(140, 375, 520, 90).contains(Mouse::getPosition(window)))
			{
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					//Learn_ruen();
				}
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
			{
				Menu();
				return;
			}
		}
		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(text);
		window.draw(shadow1);
		window.draw(shadow2);
		window.draw(rectangle2);
		window.draw(text2);
		window.draw(shadow3);
		window.draw(shadow4);
		window.display();

	}
}

void Voc_enru()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Voc_enru");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	RectangleShape rectangle(sf::Vector2f(620, 500));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(Color(255, 239, 213));
	rectangle.setPosition(90, 50);
	rectangle.setFillColor(Color(100, 111, 125, 120));

	Wl(w);
	Voc(w);

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text0("", font, 40);

	string rus;
	string eng;
	string all;
	//struct d w[n];
	for (int i = 0; i < n; i++)
	{
		rus = (const char*)w[i].ru;
		eng = (const char*)w[i].en;
		all += eng + "-" + rus + "\n";
	}

	text0.setString((all));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(110, 70);
	

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
			{
				Vocabulary();
				return;
			}
		}
		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(text0);
		window.display();
	}

}

void Voc_ruen()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Voc_ruen");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	RectangleShape rectangle(sf::Vector2f(620, 500));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(Color(255, 239, 213));
	rectangle.setPosition(90, 50);
	rectangle.setFillColor(Color(100, 111, 125, 120));

	Wl(w);
	Voc1(w);

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text0("", font, 40);

	string rus;
	string eng;
	string all;

	for (int i = 0; i < n; i++)
	{
		rus = (const char*)w[i].ru;
		eng = (const char*)w[i].en;
		all += rus + "-" + eng + "\n";
	}

	text0.setString((all));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(110, 70);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
			{
				Vocabulary();
				return;
			}
		}
		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(text0);
		window.display();
	}

}

void Learn_enru()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Learn_enru");

	Image menuimage4;
	menuimage4.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture4;
	menuTexture4.loadFromImage(menuimage4);
	Sprite menusprite4;
	menusprite4.setTexture(menuTexture4);

	RectangleShape rectangle0(sf::Vector2f(620, 500));
	rectangle0.setOutlineThickness(1);
	rectangle0.setOutlineColor(Color(255, 239, 213));
	rectangle0.setPosition(90, 50);
	rectangle0.setFillColor(Color(100, 111, 125, 120));

	Wl(w);
	Learn1(w);

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text0("", font, 40);

	string rus;
	string eng;
	string all;
	for (int i = 0; i < n; i++)
	{
		rus = (const char*)w[i].ru;
		eng = (const char*)w[i].en;
		all += eng + "-" + rus + "\n";
	}

	text0.setString((all));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(110, 70);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Z)
			{
				Learning();
				return;
			}
		}
		window.clear();
		window.draw(menusprite4);
		window.draw(rectangle0);
		window.draw(text0);
		window.display();
	}

}
