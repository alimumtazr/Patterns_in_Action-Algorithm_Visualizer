#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <thread>
#include <chrono>
#include <unordered_map>


using namespace std;
using namespace sf;

const int WINDOW_HEIGHT = 1200;
const int WINDOW_WIDTH = 1000;
const int wh = 1200;
const int ww = 1500;
int ARRAY_SIZE = 20;
int speed = 50;
int BAR_WIDTH = (WINDOW_WIDTH / 3) / (ARRAY_SIZE / 3);
int elapsedTime = 0; // milliseconds mein hai
int minutes = 0;
int seconds = 0;
int milliseconds = 0;
bool timerRunning = false;

sf::Texture bgt;
sf::Sprite bgs;

sf::Texture bfst;
sf::Sprite bfss;

sf::Texture hmpt;
sf::Sprite hmps;

sf::Texture bot;
sf::Sprite bos;

sf::Texture b1t;
sf::Sprite b1s;

sf::Texture b2t;
sf::Sprite b2s;

sf::Texture b3t;
sf::Sprite b3s;

sf::Texture b4t;
sf::Sprite b4s;

sf::Texture b5t;
sf::Sprite b5s;

sf::Texture b6t;
sf::Sprite b6s;

sf::Texture splt;
sf::Sprite spls;

sf::Texture sprt;
sf::Sprite sprs;

sf::Texture nlt;
sf::Sprite nls;

sf::Texture nrt;
sf::Sprite nrs;

sf::Texture ret;
sf::Sprite res;

sf::Texture timet;
sf::Sprite times;

sf::SoundBuffer beepBuffer;
sf::Sound beepSound;

sf::SoundBuffer tBuffer;
sf::Sound tSound;

sf::SoundBuffer clickBuffer;
sf::Sound clickSound;


sf::Text nnp;

sf::Text sp;

sf::Text timerText;

sf::Clock timerClock;

std::string intToString(int value)
{
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

void updateTimer()
{
    if (timerRunning)
    {
        sf::Time deltaTime = timerClock.restart();
        elapsedTime += deltaTime.asMilliseconds();

        int minutes = elapsedTime / 60000;
        int seconds = (elapsedTime % 60000) / 1000;
        int milliseconds = (elapsedTime % 1000) / 10; // Deciseconds

        timerText.setString(intToString(minutes) + "m " + intToString(seconds) + "s " + intToString(milliseconds) + "ms");
    }
}

void render(sf::RenderWindow& window)
{
    window.draw(bgs);
    window.draw(bos);
    window.draw(bfss);
    window.draw(hmps);
    window.draw(b1s);
    window.draw(b2s);
    window.draw(b3s);
    window.draw(b4s);
    window.draw(b5s);
    window.draw(b6s);
    window.draw(spls);
    window.draw(sprs);
    window.draw(nls);
    window.draw(nrs);
    window.draw(sp);
    window.draw(nnp);
    window.draw(res);
    window.draw(times);

    window.draw(timerText);
}

void drawArray(sf::RenderWindow& window, const std::vector<int>& array, int id1, int id2, bool q, bool f)
{
    window.clear();
    render(window);
    if (f == false)
    {
        updateTimer();
    }
    for (int i = 0; i < array.size(); i++)
    {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH - 2, array[i]));
        if (i == id2)
        {
            bar.setFillColor(sf::Color::Green);
        }
        else if (i == id1)
        {
            bar.setFillColor(sf::Color::Red);
            tSound.play();
        }
        else
        {
            bar.setFillColor(sf::Color::White);
        }
        bar.setPosition(i * BAR_WIDTH + 50, WINDOW_HEIGHT - array[i] + 50);
        window.draw(bar);
    }
    if (q == true)
    {
        for (int i = 0; i < array.size(); i++)
        {
            sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH - 2, array[i]));
            bar.setFillColor(sf::Color::Green);
            bar.setPosition(i * BAR_WIDTH + 50, WINDOW_HEIGHT - array[i] + 50);
            window.draw(bar);
        }
    }
    window.display();
}
