#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <windows.h>

using namespace std;

const int WINDOW_HEIGHT = 1200;
const int WINDOW_WIDTH = 1000;
const int wh = 1500;
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

sf::Texture bot;
sf::Sprite bos;

sf::Texture solgt;
sf::Sprite solgs;

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

sf::Text sped;

sf::Text nnp;

sf::Text sp;

sf::Text timerText;

sf::Clock timerClock; 
string intToString(int value)
{
    ostringstream oss;
    oss << value;
    return oss.str();
}

void updateTimer()
{
    if(timerRunning)
    {
        sf::Time deltaTime = timerClock.restart();
        elapsedTime += deltaTime.asMilliseconds();

        int minutes = elapsedTime / 60000;
        int seconds = (elapsedTime % 60000) / 1000;
        int milliseconds = (elapsedTime % 1000) / 10; // Deciseconds

        timerText.setString(intToString(minutes) + "m " + intToString(seconds) + "s " + intToString(milliseconds) + "ms");
    }
}
void render(sf::RenderWindow &window)
{
	window.draw(bgs);
    window.draw(bos);
    window.draw(solgs);
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
    window.draw(sped);
    window.draw(timerText);
}

void drawArray(sf::RenderWindow &window, const std::vector<int> &array, int id1 , int id2, bool q, bool f)
{
    window.clear();
    render(window);
    if(f == false)
    {
    	updateTimer();
	}
    for(int i = 0; i < array.size(); i++)
    {
        sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH - 2, array[i]));
        if(i == id2)
		{
            bar.setFillColor(sf::Color::Green);
        }
		else if(i == id1)
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
    if(q == true)
    {
    	for(int i = 0 ; i < array.size() ; i++)
    	{
    		sf::RectangleShape bar(sf::Vector2f(BAR_WIDTH - 2, array[i]));
            bar.setFillColor(sf::Color::Green);
            bar.setPosition(i * BAR_WIDTH + 50, WINDOW_HEIGHT - array[i] + 50);
            window.draw(bar);
		}
	}
    window.display();
}
void bubbleSort(sf::RenderWindow &window, vector<int> &array)
{
    for(int i = 0 ; i < array.size() - 1 ; i++)
    {
        for(int j = 0 ; j < array.size() - i - 1 ; j++)
        {
        	if(!window.isOpen())
            {
                beepSound.stop(); 
                return;   
            }
            if(array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
            drawArray(window, array , j , j + 1 , false , false);
            beepSound.play();
            sf::Event event;
            while(window.pollEvent(event))
            {
                if(event.type == sf::Event::Closed)
                {   
                    beepSound.stop();
                    window.close();
                }
            }
            sleep(sf::milliseconds(speed));
        }
    }
}

void mergeSort(sf::RenderWindow &window, vector<int>& array)
{
    int n = array.size();
    vector<int> temp(n);

    for(int size = 1 ; size < n ; size *= 2)
	{
        for(int leftStart = 0 ; leftStart < n ; leftStart += 2 * size)
		{
            int mid = min(leftStart + size - 1 , n - 1);
            int rightEnd = min(leftStart + 2 * size - 1 , n - 1);
            int i = leftStart;
            int j = mid + 1;
            int k = leftStart;

            while(i <= mid && j <= rightEnd)
			{
                if(array[i] <= array[j])
				{
                    temp[k++] = array[i++];
                }
				else
				{
                    temp[k++] = array[j++];
                }
            }

            while(i <= mid)
			{
                temp[k++] = array[i++];
            }

            while(j <= rightEnd)
			{
                temp[k++] = array[j++];
            }

            for(int m = leftStart; m <= rightEnd; m++)
			{
                array[m] = temp[m];
            }

            drawArray(window, array, leftStart, rightEnd, false , false);
            beepSound.play();
            sf::Event event;
            while(window.pollEvent(event))
			{
                if(event.type == sf::Event::Closed)
				{
					beepSound.stop();
                    window.close();
                    return; 
                }
            }
            sleep(sf::milliseconds(speed));
        }
    }
}

void insertionSort(sf::RenderWindow &window, vector<int>& array)
{
    int n = array.size();
    
    for(int i = 1 ; i < n ; i++)
    {
    	int j = i - 1;
    	int k = array[i];
    	while(j >= 0 && array[j] > k)
    	{
    		array[j + 1] = array[j];
    		j--;
    		drawArray(window, array, i, j + 1, false , false);
    		beepSound.play();
    		sf::Event event;
            while(window.pollEvent(event))
			{
                if(event.type == sf::Event::Closed)
				{
					beepSound.stop();
                    window.close();
                    return; 
                }
            }
            sleep(sf::milliseconds(speed));
		}
		array[j + 1] = k;
	}
}

void selectionSort(sf::RenderWindow &window, vector<int>& array)
{
    int n = array.size();
    vector<int> temp(n);
    
	for(int i = 0 ; i < n - 1 ; i++)
	{
		int k = i;
		for(int j = i + 1 ; j < n ; j++)
		{
			if(array[j] < array[k])
			{
				k = j;
			}
			drawArray(window, array, i , j , false , false);
			beepSound.play();
    		sf::Event event;
            while(window.pollEvent(event))
			{
                if(event.type == sf::Event::Closed)
				{
					beepSound.stop();
                    window.close();
                    return; 
                }
            }
            sleep(sf::milliseconds(speed));
		}
		int temp = array[i];
		array[i] = array[k];
		array[k] = temp;
	}
}
void quickSort(sf::RenderWindow &window, vector<int>& array)
{
    vector<int> indices;
    indices.push_back(0);
    indices.push_back(array.size() - 1);

    while(!indices.empty())
	{
        int high = indices.back(); indices.pop_back();
        int low = indices.back(); indices.pop_back();

        if(low < high)
		{
            int pivot = array[high];
            int i = low - 1;

            for(int j = low; j < high; j++)
			{
                if(array[j] < pivot)
				{
                    i++;
                    std::swap(array[i], array[j]);
                    drawArray(window, array, i, j, false , false);

                    sf::Event event;
                    while (window.pollEvent(event))
					{
                        if(event.type == sf::Event::Closed)
						{
							beepSound.stop();
                            window.close();
                            return;
                        }
                    }
                    sleep(sf::milliseconds(speed));
                }
            }
            int temp = array[i + 1];
            array[i + 1] = array[high];
            array[high] = temp;
            drawArray(window, array, i + 1, high, false , false);
            beepSound.play();
            sf::Event event;
            while(window.pollEvent(event))
			{
                if(event.type == sf::Event::Closed)
				{
					beepSound.stop();
                    window.close();
                    return;
                }
            }
            sleep(sf::milliseconds(speed));

            int pivotIndex = i + 1;

            indices.push_back(low);
            indices.push_back(pivotIndex - 1); 
            indices.push_back(pivotIndex + 1);
            indices.push_back(high); 
        }
    }
}

void shellSort(sf::RenderWindow &window, vector<int>& array)
{
    int n = array.size();
    int gap = n / 2; 
    while(gap > 0)
	{
        for(int i = gap; i < n; i++)
		{
            int temp = array[i];
            int j = i;
            while(j >= gap && array[j - gap] > temp)
			{
                array[j] = array[j - gap];
                drawArray(window , array , j , j - gap , false , false);
                beepSound.play();
                sf::Event event;
                while(window.pollEvent(event))
				{
                    if(event.type == sf::Event::Closed)
					{
						beepSound.stop();
                        window.close();
                        return;
                    }
                }
                sleep(sf::milliseconds(speed));
                j -= gap;
            }
            array[j] = temp;
            drawArray(window , array , j , i , false , false);
            beepSound.play();
            sf::Event event;
            while(window.pollEvent(event))
			{
                if(event.type == sf::Event::Closed)
                {
                	beepSound.stop();
                    window.close();
                    return;
                }
            }
            sleep(sf::milliseconds(speed));
        }
        gap /= 2; 
    }
}
void software(sf::RenderWindow &window)
{
    window.draw(timerText);
    BAR_WIDTH = WINDOW_WIDTH / ARRAY_SIZE;
    vector<int> array(ARRAY_SIZE);
    bool done = false;

    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        array[i] = std::rand() % (WINDOW_HEIGHT - 200) + 20;
    }

    timerText.setString(intToString(minutes) + "m " + intToString(seconds) + "s " + intToString(milliseconds) + "ms");

    while(window.isOpen())
    {
        drawArray(window, array, -1, -1, false, true);

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                beepSound.stop();
                window.close();
            }
	    else if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
            {
                if(b1s.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
                {
                    clickSound.play();
                    sped.setString("Bubble");
                    if(done == true)
                    {
                        for(int i = 0; i < ARRAY_SIZE; i++)
                        {
                            array[i] = std::rand() % (WINDOW_HEIGHT - 200) + 20;
                        }
                        drawArray(window, array, 0, 0, false, true);
                        sleep(sf::milliseconds(500));
                    }
                    elapsedTime = 0;
                    timerClock.restart();
                    timerRunning = true;
                    bubbleSort(window, array);
                    timerRunning = false;
                    sleep(sf::milliseconds(500));
                    for(int i = 0; i < ARRAY_SIZE; i++)
                    {
                        drawArray(window, array, -1, i, false, true);
                        sleep(sf::milliseconds(50));
                        if(window.isOpen())
                        {
                            beepSound.play();
                        }
                    }
                    sleep(sf::milliseconds(500));
                    done = true;
                }
else if(b2s.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
                {
                    clickSound.play();
                    sped.setString("Selection");
                    if(done == true)
                    {
                        for(int i = 0; i < ARRAY_SIZE; i++)
                        {
                            array[i] = std::rand() % (WINDOW_HEIGHT - 200) + 20;
                        }
                        drawArray(window, array, 0, 0, false, true);
                        sleep(sf::milliseconds(500));
                    }
                    elapsedTime = 0;
                    timerClock.restart();
                    timerRunning = true;
                    selectionSort(window, array);
                    timerRunning = false;
                    sleep(sf::milliseconds(500));
                    for(int i = 0; i < ARRAY_SIZE; i++)
                    {
                        drawArray(window, array, -1, i, false, true);
                        sleep(sf::milliseconds(50));
                        if(window.isOpen())
                        {
                            beepSound.play();
                        }
                    }
                    sleep(sf::milliseconds(500));
                    done = true;
                }
                else if(b3s.getGlobalBounds().contains(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y)))
                {
                    clickSound.play();
                    sped.setString("Insertion");
                    if(done == true)
                    {
                        for(int i = 0; i < ARRAY_SIZE; i++)
                        {
                            array[i] = std::rand() % (WINDOW_HEIGHT - 200) + 20;
                        }
                        drawArray(window, array, 0, 0, false, true);
                        sleep(sf::milliseconds(500));
                    }
                    elapsedTime = 0;
                    timerClock.restart();
                    timerRunning = true;
                    insertionSort(window, array);
                    timerRunning = false;
                    sleep(sf::milliseconds(500));
                    for(int i = 0; i < ARRAY_SIZE; i++)
                    {
                        drawArray(window, array, -1, i, false, true);
                        sleep(sf::milliseconds(50));
                        if(window.isOpen())
                        {
                            beepSound.play();
                        }
                    }
                    sleep(sf::milliseconds(500));
                    done = true;
                }
            }
        }
    }
}
	} //more code to be added accordingly, please work on it and check whatsapp group for more descriptions of the next steps
