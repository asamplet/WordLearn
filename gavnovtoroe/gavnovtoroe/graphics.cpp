#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "WordLearn.h"
#include "pch.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#pragma warning(disable : 4996)
#define n 30

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
void Learn_ruen();
void Completed();
struct d w[n];
int a = 0, b = 15, c = 15, d = 30;

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
	textmenu.setPosition(130, 190);
	Text textmenu2("нажмите на любую клавишу",fontmenu, 25);
	textmenu2.setColor(Color(255, 239, 213, 100));
	textmenu2.setPosition(220, 330);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseButtonPressed
				&& event.mouseButton.button == sf::Mouse::Left || event.type == Event::KeyPressed)
			{
				Menu();
				break;
			}

		}

		window.clear();
		window.draw(backgroundsprite);
		window.draw(textmenu);
		window.draw(textmenu2);
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
	rectangle.setPosition(240, 180);
	rectangle.setFillColor(Color(198, 126, 195));
	sf::RectangleShape rectangle2(sf::Vector2f(320, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(250, 193, 143));
	rectangle2.setPosition(240, 375);
	rectangle2.setFillColor(Color(250, 169, 99));

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text("Словарь", font, 50);
	text.setColor(Color(255, 239, 213));
	text.setStyle(sf::Text::Bold);
	text.setPosition(300, 190);
	Text text2("Изучение", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(285, 385);
	Text text3("Выберите режим", font, 60);
	text3.setColor(Color(255, 239, 213));
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(145, 50);

	sf::ConvexShape shadow;

	shadow.setPointCount(4);

	shadow.setPoint(0, sf::Vector2f(230, 170));
	shadow.setPoint(1, sf::Vector2f(240, 180));
	shadow.setPoint(2, sf::Vector2f(240, 270));
	shadow.setPoint(3, sf::Vector2f(230, 280));
	shadow.setFillColor(Color(175, 109, 173));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(560, 180));
	shadow2.setPoint(1, sf::Vector2f(570, 170));
	shadow2.setPoint(2, sf::Vector2f(570, 280));
	shadow2.setPoint(3, sf::Vector2f(560, 270));
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

	sf::RectangleShape rectangle0(sf::Vector2f(340, 110));
	rectangle0.setFillColor(Color(70, 130, 180, 0));
	rectangle0.setPosition(230, 170);
	sf::RectangleShape rectangle01(sf::Vector2f(340, 110));
	rectangle01.setFillColor(Color(70, 130, 180, 0));
	rectangle01.setPosition(230, 365);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (IntRect(240, 160, 320, 90).contains(Mouse::getPosition(window)))
			{
				rectangle0.setFillColor(Color(70, 130, 180, 130));

				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Vocabulary();
					return;
				}
			} 
			else rectangle0.setFillColor(Color(70, 130, 180, 0));
			if (IntRect(240, 375, 320, 90).contains(Mouse::getPosition(window)))
			{
				rectangle01.setFillColor(Color(70, 130, 180, 130));
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Learning();
					return;
				}
			}
			else rectangle01.setFillColor(Color(70, 130, 180, 0));
			window.clear();
			window.draw(menusprite1);
			window.draw(rectangle);
			window.draw(shadow);
			window.draw(shadow2);
			window.draw(text);
			window.draw(rectangle0);
			window.draw(rectangle2);
			window.draw(shadow3);
			window.draw(shadow4);
			window.draw(text2);
			window.draw(rectangle01);
			window.draw(text3);
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
	text.setPosition(210, 190);
	Text text2("Русско-английский", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(160, 385);
	Text text3("Выберите словарь", font, 60);
	text3.setColor(Color(255, 239, 213));
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(125, 50);

	sf::RectangleShape rectangle(sf::Vector2f(520, 90));
	rectangle.setOutlineThickness(10);
	rectangle.setOutlineColor(Color(216, 148, 214));
	rectangle.setPosition(140, 180);
	rectangle.setFillColor(Color(198, 126, 195));
	sf::RectangleShape rectangle2(sf::Vector2f(520, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(216, 148, 214));
	rectangle2.setPosition(140, 375);
	rectangle2.setFillColor(Color(198, 126, 195));

	sf::ConvexShape shadow1;

	shadow1.setPointCount(4);

	shadow1.setPoint(0, sf::Vector2f(130, 170));
	shadow1.setPoint(1, sf::Vector2f(140, 180));
	shadow1.setPoint(2, sf::Vector2f(140, 270));
	shadow1.setPoint(3, sf::Vector2f(130, 280));
	shadow1.setFillColor(Color(175, 109, 173));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(660, 180));
	shadow2.setPoint(1, sf::Vector2f(670, 170));
	shadow2.setPoint(2, sf::Vector2f(670, 280));
	shadow2.setPoint(3, sf::Vector2f(660, 270));
	shadow2.setFillColor(Color(175, 109, 173));

	sf::ConvexShape shadow3;

	shadow3.setPointCount(4);

	shadow3.setPoint(0, sf::Vector2f(130, 365));
	shadow3.setPoint(1, sf::Vector2f(140, 375));
	shadow3.setPoint(2, sf::Vector2f(140, 465));
	shadow3.setPoint(3, sf::Vector2f(130, 475));
	shadow3.setFillColor(Color(175, 109, 173));

	sf::ConvexShape shadow4;

	shadow4.setPointCount(4);

	shadow4.setPoint(0, sf::Vector2f(660, 375));
	shadow4.setPoint(1, sf::Vector2f(670, 365));
	shadow4.setPoint(2, sf::Vector2f(670, 475));
	shadow4.setPoint(3, sf::Vector2f(660, 465));
	shadow4.setFillColor(Color(175, 109, 173));

	sf::RectangleShape rectangle0(sf::Vector2f(540, 110));
	rectangle0.setFillColor(Color(70, 130, 180, 0));
	rectangle0.setPosition(130, 170);
	sf::RectangleShape rectangle01(sf::Vector2f(540, 110));
	rectangle01.setFillColor(Color(70, 130, 180, 0));
	rectangle01.setPosition(130, 365);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (IntRect(140, 180, 520, 90).contains(Mouse::getPosition(window)))
			{
				rectangle0.setFillColor(Color(70, 130, 180, 130));
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					Voc_enru();
				}
			}
			else rectangle0.setFillColor(Color(70, 130, 180, 0));

			if (IntRect(140, 375, 520, 90).contains(Mouse::getPosition(window)))
			{
				rectangle01.setFillColor(Color(70, 130, 180, 130));
				if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
				{
					Voc_ruen();
				}
			}
			else rectangle01.setFillColor(Color(70, 130, 180, 0));

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
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
			window.draw(rectangle0);
			window.draw(rectangle2);
			window.draw(text2);
			window.draw(shadow3);
			window.draw(shadow4);
			window.draw(rectangle01);
			window.draw(text3);
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
	text.setPosition(210, 190);
	Text text2("Русско-английский", font, 50);
	text2.setColor(Color(255, 239, 213));
	text2.setStyle(sf::Text::Bold);
	text2.setPosition(160, 385);
	Text text3("Выберите режим изучения", font, 55);
	text3.setColor(Color(255, 239, 213));
	text3.setStyle(sf::Text::Bold);
	text3.setPosition(20, 50);

	sf::RectangleShape rectangle(sf::Vector2f(520, 90));
	rectangle.setOutlineThickness(10);
	rectangle.setOutlineColor(Color(250, 193, 143));
	rectangle.setPosition(140, 180);
	rectangle.setFillColor(Color(250, 169, 99));
	sf::RectangleShape rectangle2(sf::Vector2f(520, 90));
	rectangle2.setOutlineThickness(10);
	rectangle2.setOutlineColor(Color(250, 193, 143));
	rectangle2.setPosition(140, 375);
	rectangle2.setFillColor(Color(250, 169, 99));

	sf::ConvexShape shadow1;

	shadow1.setPointCount(4);

	shadow1.setPoint(0, sf::Vector2f(130, 170));
	shadow1.setPoint(1, sf::Vector2f(140, 180));
	shadow1.setPoint(2, sf::Vector2f(140, 270));
	shadow1.setPoint(3, sf::Vector2f(130, 280));
	shadow1.setFillColor(Color(212, 150, 97));

	sf::ConvexShape shadow2;

	shadow2.setPointCount(4);

	shadow2.setPoint(0, sf::Vector2f(660, 180));
	shadow2.setPoint(1, sf::Vector2f(670, 170));
	shadow2.setPoint(2, sf::Vector2f(670, 280));
	shadow2.setPoint(3, sf::Vector2f(660, 270));
	shadow2.setFillColor(Color(212, 150, 97));

	sf::ConvexShape shadow3;

	shadow3.setPointCount(4);

	shadow3.setPoint(0, sf::Vector2f(130, 365));
	shadow3.setPoint(1, sf::Vector2f(140, 375));
	shadow3.setPoint(2, sf::Vector2f(140, 465));
	shadow3.setPoint(3, sf::Vector2f(130, 475));
	shadow3.setFillColor(Color(212, 150, 97));

	sf::ConvexShape shadow4;

	shadow4.setPointCount(4);

	shadow4.setPoint(0, sf::Vector2f(660, 375));
	shadow4.setPoint(1, sf::Vector2f(670, 365));
	shadow4.setPoint(2, sf::Vector2f(670, 475));
	shadow4.setPoint(3, sf::Vector2f(660, 465));
	shadow4.setFillColor(Color(212, 150, 97));

	sf::RectangleShape rectangle0(sf::Vector2f(540, 110));
	rectangle0.setFillColor(Color(70, 130, 180, 0));
	rectangle0.setPosition(130, 170);
	sf::RectangleShape rectangle01(sf::Vector2f(540, 110));
	rectangle01.setFillColor(Color(70, 130, 180, 0));
	rectangle01.setPosition(130, 365);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (IntRect(140, 160, 520, 90).contains(Mouse::getPosition(window)))
			{
				rectangle0.setFillColor(Color(70, 130, 180, 130));
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Learn_enru();
				}
			}
			else rectangle0.setFillColor(Color(70, 130, 180, 0));

			if (IntRect(140, 375, 520, 90).contains(Mouse::getPosition(window)))
			{
				rectangle01.setFillColor(Color(70, 130, 180, 130));
				if (event.type == sf::Event::MouseButtonPressed
					&& event.mouseButton.button == sf::Mouse::Left)
				{
					Learn_ruen();
				}
			}
			else rectangle01.setFillColor(Color(70, 130, 180, 0));

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
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
		window.draw(rectangle0);
		window.draw(rectangle2);
		window.draw(text2);
		window.draw(shadow3);
		window.draw(shadow4);
		window.draw(rectangle01);
		window.draw(text3);
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
	Text text0("", font, 30);
	Text text01("", font, 30);

	string rus;
	string eng;
	string all;
	string all2;

	for ( a ; a < b; a++)
	{
		rus = (const char*)w[a].ru;
		eng = (const char*)w[a].en;
		all += eng + "-" + rus + "\n";
	}

	text0.setString((all));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(110, 70);

	for (c; c < d; c++)
	{
		rus = (const char*)w[c].ru;
		eng = (const char*)w[c].en;
		all2 += eng + "-" + rus + "\n";
	}
	text01.setString((all2));
	text01.setColor(Color(255, 239, 213));
	text01.setPosition(410, 70);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
			{
				Vocabulary();
				return;
			}

		}

		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(text0);
		window.draw(text01);
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
	Voc(w);

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text text0("", font, 30);
	Text text01("", font, 30);

	string rus;
	string eng;
	string all;
	string all2;

	for (a; a < b; a++)
	{
		rus = (const char*)w[a].ru;
		eng = (const char*)w[a].en;
		all += rus + "-" + eng + "\n";
	}

	text0.setString((all));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(110, 70);

	for (c; c < d; c++)
	{
		rus = (const char*)w[c].ru;
		eng = (const char*)w[c].en;
		all2 += rus + "-" + eng + "\n";
	}
	text01.setString((all2));
	text01.setColor(Color(255, 239, 213));
	text01.setPosition(410, 70);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
			{
				Vocabulary();
				return;
			}
		}

		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(text0);
		window.draw(text01);
		window.display();
	}
}

void Learn_enru()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Learn_enru");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	RectangleShape rectangle(sf::Vector2f(620, 400));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(Color(255, 239, 213));
	rectangle.setPosition(90, 100);
	rectangle.setFillColor(Color(100, 111, 125, 120));
	RectangleShape rectangle2(sf::Vector2f(270, 50));
	rectangle2.setOutlineThickness(1);
	rectangle2.setOutlineColor(Color(255, 239, 213));
	rectangle2.setPosition(420, 250);
	rectangle2.setFillColor(Color(100, 111, 125, 190)); 

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text title("Введите перевод слова", font, 55);
	title.setColor(Color(255, 239, 213));
	title.setStyle(sf::Text::Bold);
	title.setPosition(70, 30);

	Wl(w);
	Voc(w);

	Text text0("", font, 50);
	Text text01("", font, 50);
	Text text1("", font, 40);
	Text text_("-", font, 50);
	Text slovo("слово:", font, 50);
	Text perevod("перевод:", font, 50);

	string eng;
	string rus;
	string st;

	eng = (const char*)w[0].en;
	rus = (const char*)w[0].ru;

	text0.setString((eng));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(150, 240);
	text01.setColor(Color(255, 239, 213));
	text01.setPosition(430, 240);
	text_.setColor(Color(255, 239, 213));
	text_.setPosition(400, 240);
	slovo.setColor(Color(255, 239, 213, 200));
	slovo.setPosition(170, 120);
	perevod.setColor(Color(255, 239, 213, 200));
	perevod.setPosition(450, 120);
	
	int count = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
			{
				Learning();
				return;
			}

			if (event.type == sf::Event::TextEntered) 
		{
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) 
					{
						char s = 'й';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
					{
						char s = 'ц';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
					{
						char s = 'у';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) 
					{
						char s = 'к';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) 
					{
						char s = 'е';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) 
					{
						char s = 'н';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
					{
						char s = 'г';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) 
					{
						char s = 'ш';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) 
					{
						char s = 'щ';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
					{
						char s = 'з';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) 
					{
						char s = 'х';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket))
					{
						char s = 'ъ';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
					{
						char s = 'ф';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
					{
						char s = 'ы';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
					{
						char s = 'в';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) 
					{
						char s = 'а';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) 
					{
						char s = 'п';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) 
					{
						char s = 'р';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) 
					{
						char s = 'о';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) 
					{
						char s = 'л';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) 
					{
						char s = 'д';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) 
					{
						char s = 'ж';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) 
					{
						char s = 'э';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) 
					{
						char s = 'я';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) 
					{
						char s = 'ч';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) 
					{
						char s = 'с';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) 
					{
						char s = 'м';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) 
					{
						char s = 'и';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) 
					{
						char s = 'т';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) 
					{
						char s = 'ь';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) 
					{
						char s = 'б';
						st.push_back(s);
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) 
					{
						char s = 'ю';
						st.push_back(s);
					} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && st.size() != 0) 
					{
						st.erase(st.size() - 1, 1);
					}

					text01.setString(st);
			}

			if (count != 30)
			{
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && rus == st)
				{
					st.clear();
					count++;
					eng = (const char*)w[count].en;
					rus = (const char*)w[count].ru;
					text0.setString(eng);
				}

				else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && rus != st)
					st.clear();
			}
			else
				Completed();
		}

		window.clear();
		window.draw(menusprite);
		window.draw(title);
		window.draw(rectangle);
		window.draw(slovo);
		window.draw(perevod);
		window.draw(rectangle2);
		window.draw(text0);
		window.draw(text_);
		window.draw(text01);
		window.display();
	}
}

void Learn_ruen()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Learn_ruen");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	RectangleShape rectangle(sf::Vector2f(620, 400));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(Color(255, 239, 213));
	rectangle.setPosition(90, 100);
	rectangle.setFillColor(Color(100, 111, 125, 120));
	RectangleShape rectangle2(sf::Vector2f(270, 50));
	rectangle2.setOutlineThickness(1);
	rectangle2.setOutlineColor(Color(255, 239, 213));
	rectangle2.setPosition(420, 250);
	rectangle2.setFillColor(Color(100, 111, 125, 190)); 

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text title("Введите перевод слова", font, 55);
	title.setColor(Color(255, 239, 213));
	title.setStyle(sf::Text::Bold);
	title.setPosition(70, 30);

	Wl(w);
	Voc(w);

	Text text0("", font, 50);
	Text text01("", font, 50);
	Text text1("", font, 40);
	Text text_("-", font, 50);
	Text slovo("слово:", font, 50);
	Text perevod("перевод:", font, 50);

	string eng;
	string rus;

	eng = (const char*)w[0].en;
	rus = (const char*)w[0].ru;
	string st;

	text0.setString((rus));
	text0.setColor(Color(255, 239, 213));
	text0.setPosition(150, 240);
	text01.setColor(Color(255, 239, 213));
	text01.setPosition(430, 240);
	text_.setColor(Color(255, 239, 213));
	text_.setPosition(400, 240);
	slovo.setColor(Color(255, 239, 213, 200));
	slovo.setPosition(170, 120);
	perevod.setColor(Color(255, 239, 213, 200));
	perevod.setPosition(450, 120);

	int count = 0;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
			{
				Learning();
				return;
			}

			if (event.type == sf::Event::TextEntered) 
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) 
				{
					char s = 'q';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) 
				{
					char s = 'w';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) 
				{
					char s = 'e';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) 
				{
					char s = 'r';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) 
				{
					char s = 't';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) 
				{
					char s = 'y';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) 
				{
					char s = 'u';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) 
				{
					char s = 'i';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) 
				{
					char s = 'o';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) 
				{
					char s = 'p';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
				{
					char s = 'a';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) 
				{
					char s = 's';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
				{
					char s = 'd';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) 
				{
					char s = 'f';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) 
				{
					char s = 'g';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) 
				{
					char s = 'h';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) 
				{
					char s = 'j';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) 
				{
					char s = 'k';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) 
				{
					char s = 'l';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) 
				{
					char s = 'z';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) 
				{
					char s = 'x';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) 
				{
					char s = 'c';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) 
				{
					char s = 'v';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) 
				{
					char s = 'b';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) 
				{
					char s = 'n';
					st.push_back(s);
				}
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) 
				{
					char s = 'm';
					st.push_back(s);
				} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Backspace) && st.size() != 0) 
				{
					st.erase(st.size() - 1, 1);
				}

				text01.setString(st);
			}

			if (count != 30) 
			{
				if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && eng == st)
				{
					st.clear();
					count++;
					eng = (const char*)w[count].en;
					rus = (const char*)w[count].ru;
					text0.setString(rus);
				}

				else if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter && eng != st)
					st.clear();
			}
			else
				Completed();
		}

		window.clear();
		window.draw(menusprite);
		window.draw(title);
		window.draw(rectangle);
		window.draw(slovo);
		window.draw(perevod);
		window.draw(rectangle2);
		window.draw(text0);
		window.draw(text_);
		window.draw(text01);
		window.display();
	}
}

void Completed()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	window.setTitle("Completed");

	Image menuimage;
	menuimage.loadFromFile("C:/Users/DNS-PC/Desktop/image/inoutputwindow.png");
	Texture menuTexture;
	menuTexture.loadFromImage(menuimage);
	Sprite menusprite;
	menusprite.setTexture(menuTexture);

	RectangleShape rectangle(sf::Vector2f(660, 400));
	rectangle.setOutlineThickness(1);
	rectangle.setOutlineColor(Color(255, 239, 213));
	rectangle.setPosition(70, 100);
	rectangle.setFillColor(Color(100, 111, 125, 120));

	Font font;
	font.loadFromFile("benguiat-rus_[allfont.ru].ttf");
	Text title("Вы успешно прошли изучение", font, 40);
	title.setColor(Color(255, 239, 213));
	title.setStyle(sf::Text::Bold);
	title.setPosition(80, 220);
	Text text("нажмите Tab", font, 25);
	text.setColor(Color(255, 239, 213, 100));
	text.setPosition(310, 280);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Tab)
			{
				Learning();
				return;
			}
		}

		window.clear();
		window.draw(menusprite);
		window.draw(rectangle);
		window.draw(title);
		window.draw(text);
		window.display();
	}
}