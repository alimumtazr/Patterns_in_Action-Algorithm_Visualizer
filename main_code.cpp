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

void bubbleSort(sf::RenderWindow& window, std::vector<int>& array)
{
    for (int i = 0; i < array.size() - 1; i++)
    {
        for (int j = 0; j < array.size() - i - 1; j++)
        {
            if (!window.isOpen())
            {
                beepSound.stop();
                return;
            }
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
            drawArray(window, array, j, j + 1, false, false);
            beepSound.play();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    beepSound.stop();
                    window.close();
                }
            }
            sleep(sf::milliseconds(speed));
        }
    }
}

// Function to merge two sorted subarrays
void merge(vector<int>& array, vector<int>& temp, int leftStart, int mid, int rightEnd) {
    int leftIndex = leftStart;
    int rightIndex = mid + 1;
    int tempIndex = leftStart;

    // Merge the two subarrays into the temporary array
    while (leftIndex <= mid && rightIndex <= rightEnd) {
        if (array[leftIndex] <= array[rightIndex]) {
            temp[tempIndex++] = array[leftIndex++];
        }
        else {
            temp[tempIndex++] = array[rightIndex++];
        }
    }

    while (leftIndex <= mid) {
        temp[tempIndex++] = array[leftIndex++];
    }

    while (rightIndex <= rightEnd) {
        temp[tempIndex++] = array[rightIndex++];
    }

    // Copy the merged subarray back to the original array
    for (int i = leftStart; i <= rightEnd; i++) {
        array[i] = temp[i];
    }
}

// Function for recursively dividing the array into subarrays and visualizing progress
void mergeSortRecursive(sf::RenderWindow& window, vector<int>& array, vector<int>& temp, int leftStart, int rightEnd, int speed) {
    if (leftStart >= rightEnd) {
        return;
    }

    int mid = (leftStart + rightEnd) / 2;

    // Recursively split the array
    mergeSortRecursive(window, array, temp, leftStart, mid, speed);
    mergeSortRecursive(window, array, temp, mid + 1, rightEnd, speed);

    // Merge the two halves
    merge(array, temp, leftStart, mid, rightEnd);

    // Visualize the array after each merge step
    drawArray(window, array, leftStart, rightEnd, false, false);

    // Handle window events
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            return;
        }
    }

    // Add a delay to visualize the sorting process (adjust speed as needed)
    std::this_thread::sleep_for(std::chrono::milliseconds(speed));
}

// Merge Sort function to initialize the sorting proce
void mergeSort(sf::RenderWindow& window, vector<int>& array) {
    int n = array.size();
    vector<int> temp(n);  // Temporary array for merging

    // Initially perform recursive merge sort
    mergeSortRecursive(window, array, temp, 0, n - 1, speed);

    // After sorting, draw the final sorted array
    drawArray(window, array, 0, n - 1, false, false);
}


void insertionSort(sf::RenderWindow& window, vector<int>& array)
{
    int n = array.size();

    // Dynamically allocate the stack array based on the size of the input array
    int* shiftStack = new int[n];  // Dynamically allocated stack array
    int top = -1;  // Stack pointer

    for (int i = 1; i < n; i++)
    {
        int key = array[i];
        int j = i - 1;

        // Shift elements greater than key into the stack (simulate push)
        while (j >= 0 && array[j] > key)
        {
            shiftStack[++top] = array[j];  // Push onto stack
            array[j + 1] = array[j]; // Temporarily shift in array for visualization

            drawArray(window, array, i, j + 1, false, false);  // Visualization of array
            beepSound.play();

            // Handle window events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    delete[] shiftStack;  // Clean up dynamically allocated memory
                    return;
                }
            }
            sleep(sf::milliseconds(speed));  // Sleep for visualization effect
            j--;
        }

        // Place the key in the correct position
        array[j + 1] = key;
        drawArray(window, array, i, j + 1, true, false); // Highlight insertion

        // Rebuild the array from the stack (simulate pop)
        int rebuildIndex = j + 2;
        while (top >= 0)  // While stack is not empty
        {
            array[rebuildIndex++] = shiftStack[top--];  // Pop from stack
            drawArray(window, array, i, rebuildIndex - 1, false, true);

            // Handle window events
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window.close();
                    delete[] shiftStack;  // Clean up dynamically allocated memory
                    return;
                }
            }
            sleep(sf::milliseconds(speed));  // Sleep for visualization effect
        }
    }

    delete[] shiftStack;  // Clean up dynamically allocated memory at the end
}
