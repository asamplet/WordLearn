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
//144, 238, 144/ 143, 188, 143
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
	Text textmenu2("нажмите на любую клавишу",fontmenu, 25);
	textmenu2.setColor(Color(255, 239, 213, 100));
	textmenu2.setPosition(220, 350);

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
	Text text("Словарь", font, 50);//сам объект текст (не строка)
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
			window.draw(rectangle2);
			window.draw(text2);
			window.draw(shadow3);
			window.draw(shadow4);
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
		window.draw(rectangle2);
		window.draw(text2);
		window.draw(shadow3);
		window.draw(shadow4);
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
	rectangle2.setFillColor(Color(100, 111, 125, 190)); //198, 126, 195/216, 148, 214

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
	string left;
	string rus;
	string right;
	for (int i = 0; i < n; i++)
	{
		rus = (const char*)w[i].ru;
		eng = (const char*)w[i].en;
		left = eng + "\n";
		right = rus + "\n";
	}
	text0.setString((left));
	text1.setString((right));
	unsigned char i1 = 0, flag = 1;
	wchar_t st = L'0', st1[15] = L"\0";

	text0.setColor(Color(255, 239, 213));
	text0.setPosition(150, 240);
	text01.setColor(Color(255, 239, 213));
	text01.setPosition(430, 240);
	text_.setColor(Color(255, 239, 213));
	text_.setPosition(400, 240);
	slovo.setColor(Color(255, 239, 213, 190));
	slovo.setPosition(170, 120);
	perevod.setColor(Color(255, 239, 213, 190));
	perevod.setPosition(450, 120);

	int count = 0;

	while (window.isOpen())
	{
		//if (text0.getPosition().x + 16 > screenDimensions.x / 5)
			//position.x = text0.getPosition().x + 16;
		//else
			//position.x = screenDimensions.x / 2;

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
			if (event.type == sf::Event::TextEntered) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
						st = L'й';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
						st = L'ц';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
						st = L'у';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
						st = L'к';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
						st = L'е';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) {
						st = L'н';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::U)) {
						st = L'г';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::I)) {
						st = L'ш';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::O)) {
						st = L'щ';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::P)) {
						st = L'з';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::LBracket)) {
						st = L'х';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::RBracket)) {
						st = L'ъ';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
						st = L'ф';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
						st = L'ы';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
						st = L'в';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)) {
						st = L'а';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
						st = L'п';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)) {
						st = L'р';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) {
						st = L'о';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::K)) {
						st = L'л';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::L)) {
						st = L'д';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::SemiColon)) {
						st = L'ж';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Quote)) {
						st = L'э';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
						st = L'я';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) {
						st = L'ч';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
						st = L'с';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
						st = L'м';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
						st = L'и';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::N)) {
						st = L'т';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)) {
						st = L'ь';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Comma)) {
						st = L'б';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Period)) {
						st = L'ю';
					}
					else if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
						st = L'\0';
						flag = 2;
					}
					else
						flag = 0;
					if (flag) {
						if (flag == 2 && i1) {
							st1[i1 - 1] = L'\0';
							i1--;
						}
						if (flag == 1 && i1 < 11) {
							st1[i1] = st;
							i1++;
						}
						text01.setString(st1);
					}
					flag = 1;
			}
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
			{
				rus = (const char*)w[count].ru;
				wstring c(st1);
				const wchar_t* mocha = w[count].ru.c_str();
				if (mocha == st1)
				//char gg;
				//const char * gg = c.c_str();
				//if (strnicmp(w[count].ru, gg, sizeof(w[count].ru)))

				//if (c == rus)
				{
					//rectangle.setFillColor(Color::Blue);
					count++;
					eng = (const char*)w[count].en;
					//eng = eng + "-" + "\n";
					text0.setString(eng);
				}
			}
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

