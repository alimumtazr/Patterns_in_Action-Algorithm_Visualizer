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
struct NodeL {
    int value;
    NodeL* prev;
    NodeL* next;

    NodeL(int val) : value(val), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
public:
    NodeL* head;
    NodeL* tail;

    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Function to add a node to the list
    void push_back(int value) {
        NodeL* newNode = new NodeL(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Function to swap two nodes
    void swap(NodeL* node1, NodeL* node2) {
        if (node1 == node2) return;

        int temp = node1->value;
        node1->value = node2->value;
        node2->value = temp;
    }

    // Function to convert the linked list back to an array
    void toArray(std::vector<int>& array) {
        NodeL* current = head;
        while (current) {
            array.push_back(current->value);
            current = current->next;
        }
    }
};

// Selection Sort implementation on Doubly Linked List
void selectionSort(sf::RenderWindow& window, std::vector<int>& array) {
    // Step 1: Convert the vector to a doubly linked list
    DoublyLinkedList list;
    for (int i = 0; i < array.size(); ++i) {
        list.push_back(array[i]);
    }

    // Step 2: Perform selection sort on the doubly linked list
    NodeL* current = list.head;
    while (current && current->next) {
        NodeL* minNode = current;
        NodeL* nextNode = current->next;
        while (nextNode) {
            // Compare values to find the minimum element
            if (nextNode->value < minNode->value) {
                minNode = nextNode;
            }
            nextNode = nextNode->next;
        }

        // Swap if the minimum node is not the current node
        if (minNode != current) {
            list.swap(current, minNode);
        }

        // Step 3: Convert the sorted linked list back to an array for visualization
        std::vector<int> sortedArray;
        list.toArray(sortedArray);

        // Visualize the sorting progress
        drawArray(window, sortedArray, 0, sortedArray.size() - 1, false, false);

        // Handle window events like closing
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        sf::sleep(sf::milliseconds(100)); // Adjust speed for visualization
        current = current->next;
    }

    // After sorting, the sorted list is stored back into the vector
    std::vector<int> sortedArray;
    list.toArray(sortedArray);
    array = sortedArray; // Store the sorted array in the original vector
}

    delete[] shiftStack;  // Clean up dynamically allocated memory at the end
}

void quickSort(sf::RenderWindow& window, vector<int>& array)
{
    vector<int> indices;
    indices.push_back(0);
    indices.push_back(array.size() - 1);

    while (!indices.empty())
    {
        int high = indices.back(); indices.pop_back();
        int low = indices.back(); indices.pop_back();

        if (low < high)
        {
            int pivot = array[high];
            int i = low - 1;

            for (int j = low; j < high; j++)
            {
                if (array[j] < pivot)
                {
                    i++;
                    std::swap(array[i], array[j]);
                    drawArray(window, array, i, j, false, false);

                    sf::Event event;
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed)
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
            drawArray(window, array, i + 1, high, false, false);
            beepSound.play();
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
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

struct NodeT {
    int value;
    NodeT* left;
    NodeT* right;
    float x, y; // Position for visualization

    NodeT(int val) : value(val), left(nullptr), right(nullptr), x(0), y(0) {}
};

void drawNodeT(sf::RenderWindow& window, NodeT* node, sf::Font& font);
// Binary Search Tree Class
class BST {
public:
    NodeT* root;

    BST() : root(nullptr) {}

    // Insert a value into the BST
    NodeT* insert(NodeT* node, int value) {
        if (!node) return new NodeT(value);
        if (value < node->value)
            node->left = insert(node->left, value);
        else if (value >= node->value)
            node->right = insert(node->right, value);
        return node;
    }

    void insert(int value) {
        root = insert(root, value);
    }

    void inOrder(NodeT* root, sf::RenderWindow& window, sf::Font& font) {
        if (!root) return;

        // Traverse the left subtree
        inOrder(root->left, window, font);

        // Draw the current node
        drawNodeT(window, root, font);
        window.display(); // Refresh the window to show this node
        sf::sleep(sf::milliseconds(500)); // Add a delay for visualization

        // Traverse the right subtree
        inOrder(root->right, window, font);
    }


    NodeT* deleteNode(NodeT* node, int value) {
        if (!node) return nullptr;

        if (value < node->value)
            node->left = deleteNode(node->left, value);
        else if (value > node->value)
            node->right = deleteNode(node->right, value);
        else {
            // Node with only one child or no child
            if (!node->left) {
                NodeT* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                NodeT* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            NodeT* temp = minValueNode(node->right);
            node->value = temp->value;
            node->right = deleteNode(node->right, temp->value);
        }
        return node;
    }

    NodeT* minValueNode(NodeT* node) {
        NodeT* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }
};

void drawNodeT(sf::RenderWindow& window, NodeT* node, sf::Font& font) {
    sf::CircleShape circle(40); // Larger circle for better visibility
    circle.setFillColor(sf::Color::Red);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(node->x - 40, node->y - 40);

    sf::Text valueText;
    valueText.setFont(font);
    valueText.setString(std::to_string(node->value));
    valueText.setCharacterSize(30);
    valueText.setFillColor(sf::Color::Black);
    valueText.setPosition(node->x - 20, node->y - 20); // Centered text

    window.draw(circle);
    window.draw(valueText);
}

void drawNode(sf::RenderWindow& window, NodeT* node, sf::Font& font) {
    sf::CircleShape circle(40); // Larger circle for better visibility
    circle.setFillColor(sf::Color::White);
    circle.setOutlineThickness(3);
    circle.setOutlineColor(sf::Color::Black);
    circle.setPosition(node->x - 40, node->y - 40);

    sf::Text valueText;
    valueText.setFont(font);
    valueText.setString(std::to_string(node->value));
    valueText.setCharacterSize(30);
    valueText.setFillColor(sf::Color::Black);
    valueText.setPosition(node->x - 20, node->y - 20); // Centered text

    window.draw(circle);
    window.draw(valueText);
}


void drawTree(sf::RenderWindow& window, NodeT* node, sf::Font& font, float thickness = 5.0f, sf::Color lineColor = sf::Color::White) {
    if (!node) return;

    // Helper function to draw a thick line
    auto drawThickLine = [&](float x1, float y1, float x2, float y2, float thickness, sf::Color color) {
        sf::Vector2f direction(x2 - x1, y2 - y1);
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // Normalize and find perpendicular for thickness
        direction /= length;
        sf::Vector2f perpendicular(-direction.y, direction.x);

        sf::RectangleShape line(sf::Vector2f(length, thickness));
        line.setFillColor(color);
        line.setOrigin(0, thickness / 2);
        line.setPosition(x1, y1);
        line.setRotation(std::atan2(direction.y, direction.x) * 180.f / 3.14159265f);

        window.draw(line);
        };

    // Draw left child
    if (node->left) {
        drawThickLine(node->x, node->y, node->left->x, node->left->y, thickness, lineColor);
        drawTree(window, node->left, font, thickness, lineColor);
    }

    // Draw right child
    if (node->right) {
        drawThickLine(node->x, node->y, node->right->x, node->right->y, thickness, lineColor);
        drawTree(window, node->right, font, thickness, lineColor);
    }

    // Draw the current node
    drawNode(window, node, font);
}


void drawTreeT(sf::RenderWindow& window, NodeT* node, sf::Font& font, float thickness = 5.0f, sf::Color lineColor = sf::Color::Red) {
    if (!node) return;

    // Helper function to draw a thick line
    auto drawThickLine = [&](float x1, float y1, float x2, float y2, float thickness, sf::Color color) {
        sf::Vector2f direction(x2 - x1, y2 - y1);
        float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

        // Normalize and find perpendicular for thickness
        direction /= length;
        sf::Vector2f perpendicular(-direction.y, direction.x);

        sf::RectangleShape line(sf::Vector2f(length, thickness));
        line.setFillColor(color);
        line.setOrigin(0, thickness / 2);
        line.setPosition(x1, y1);
        line.setRotation(std::atan2(direction.y, direction.x) * 180.f / 3.14159265f);

        window.draw(line);
        };

    // Draw left child
    if (node->left) {
        drawThickLine(node->x, node->y, node->left->x, node->left->y, thickness, lineColor);
        drawTreeT(window, node->left, font, thickness, lineColor);
    }

    // Draw right child
    if (node->right) {
        drawThickLine(node->x, node->y, node->right->x, node->right->y, thickness, lineColor);
        drawTreeT(window, node->right, font, thickness, lineColor);
    }
    
    // Draw the current node
    drawNodeT(window, node, font);
}


// Position Nodes in the Tree
void positionNodes(NodeT* node, float x, float y, float offsetX) {
    if (!node) return;
    node->x = x;
    node->y = y;

    // Increase vertical spacing and adjust horizontal spacing more gradually
    positionNodes(node->left, x - offsetX, y + 100, offsetX / 1.5);
    positionNodes(node->right, x + offsetX, y + 100, offsetX / 1.5);
}


class HashmapVisualizer {
private:
    sf::RenderWindow window;
    sf::Font font;
    std::unordered_map<int, std::vector<int>> hashmap;
    const int bucketCount = 10;
    std::vector<sf::RectangleShape> buckets;
    std::unordered_map<int, std::vector<sf::CircleShape>> elements;

    // GUI elements
    sf::RectangleShape inputBox;
    sf::Text inputText;
    sf::Text titleText;
    sf::Text instructionText;
    sf::RectangleShape insertButton;
    sf::Text insertButtonText;
    sf::RectangleShape clearButton;
    sf::Text clearButtonText;
    std::string currentInput;
    bool isTyping = false;

    void initializeGUI() {
        // Title
        titleText.setFont(font);
        titleText.setString("HashMap Visualization");
        titleText.setCharacterSize(40);
        titleText.setFillColor(sf::Color::White);
        titleText.setPosition(50, 20);

        // Instructions
        instructionText.setFont(font);
        instructionText.setString("Enter a number and click Insert");
        instructionText.setCharacterSize(20);
        instructionText.setFillColor(sf::Color::White);
        instructionText.setPosition(50, 80);

        // Input box
        inputBox.setSize(sf::Vector2f(200, 40));
        inputBox.setFillColor(sf::Color::White);
        inputBox.setOutlineColor(sf::Color::Yellow);
        inputBox.setOutlineThickness(2);
        inputBox.setPosition(50, 120);

        // Input text
        inputText.setFont(font);
        inputText.setCharacterSize(24);
        inputText.setFillColor(sf::Color::Black);
        inputText.setPosition(60, 125);

        // Insert button
        insertButton.setSize(sf::Vector2f(100, 40));
        insertButton.setFillColor(sf::Color::Green);
        insertButton.setPosition(260, 120);

        insertButtonText.setFont(font);
        insertButtonText.setString("Insert");
        insertButtonText.setCharacterSize(20);
        insertButtonText.setFillColor(sf::Color::Black);
        insertButtonText.setPosition(275, 130);

        // Clear button
        clearButton.setSize(sf::Vector2f(100, 40));
        clearButton.setFillColor(sf::Color::Red);
        clearButton.setPosition(370, 120);

        clearButtonText.setFont(font);
        clearButtonText.setString("Clear");
        clearButtonText.setCharacterSize(20);
        clearButtonText.setFillColor(sf::Color::Black);
        clearButtonText.setPosition(390, 130);

        // Create buckets
        for (int i = 0; i < bucketCount; i++) {
            sf::RectangleShape bucket(sf::Vector2f(400, 50));
            bucket.setFillColor(sf::Color(50, 50, 50));
            bucket.setOutlineColor(sf::Color::Yellow);
            bucket.setOutlineThickness(2);
            bucket.setPosition(50, 200 + i * 70);
            buckets.push_back(bucket);
        }
    }

    void addElement(int key) {
        int bucketIndex = key % bucketCount;
        hashmap[bucketIndex].push_back(key);

        sf::CircleShape element(20);
        element.setFillColor(sf::Color::Red);
        element.setOutlineColor(sf::Color::Yellow);
        element.setOutlineThickness(2);

        // Position elements in a chain within the bucket
        float xPos = 470 + elements[bucketIndex].size() * 50;
        float yPos = 210 + bucketIndex * 70;
        element.setPosition(xPos, yPos);

        elements[bucketIndex].push_back(element);
    }

    void clearHashmap() {
        hashmap.clear();
        elements.clear();
    }

    void draw() {
        window.clear(sf::Color(30, 30, 30));

        window.draw(titleText);
        window.draw(instructionText);
        window.draw(inputBox);
        window.draw(inputText);
        window.draw(insertButton);
        window.draw(insertButtonText);
        window.draw(clearButton);
        window.draw(clearButtonText);

        // Draw buckets and their indices
        for (int i = 0; i < bucketCount; i++) {
            window.draw(buckets[i]);

            // Draw bucket index
            sf::Text indexText;
            indexText.setFont(font);
            indexText.setCharacterSize(20);
            indexText.setFillColor(sf::Color::Yellow);
            indexText.setString("Bucket " + std::to_string(i));
            indexText.setPosition(60, 210 + i * 70);
            window.draw(indexText);
        }

        // Draw elements and their values
        for (const auto& pair : elements) {
            int bucketIndex = pair.first;
            for (size_t i = 0; i < pair.second.size(); i++) {
                window.draw(pair.second[i]);

                // Draw the key value
                sf::Text keyText;
                keyText.setFont(font);
                keyText.setCharacterSize(18);
                keyText.setFillColor(sf::Color::White);
                keyText.setString(std::to_string(hashmap[bucketIndex][i]));

                // Center the text in the circle
                sf::Vector2f circlePos = pair.second[i].getPosition();
                keyText.setPosition(circlePos.x + 15, circlePos.y + 10);
                window.draw(keyText);
            }
        }

        window.display();
    }

public:
    HashmapVisualizer() : window(sf::VideoMode(900, 900), "Hashmap Visualization") {
        if (!font.loadFromFile("art.ttf")) {  // Use any font file you have
            std::cerr << "Error loading font\n";
            exit(1);
        }
        initializeGUI();
    }

    void run() {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();

                if (event.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

                    // Handle input box click
                    if (inputBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        isTyping = true;
                        currentInput.clear();
                        inputText.setString(currentInput);
                    }

                    // Handle insert button click
                    if (insertButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        if (!currentInput.empty()) {
                            try {
                                int key = std::stoi(currentInput);
                                addElement(key);
                                currentInput.clear();
                                inputText.setString(currentInput);
                                isTyping = false;
                            }
                            catch (const std::invalid_argument&) {
                                // Invalid input handling
                            }
                        }
                    }

                    // Handle clear button click
                    if (clearButton.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                        clearHashmap();
                    }
                }

                // Handle text input
                if (event.type == sf::Event::TextEntered && isTyping) {
                    if (event.text.unicode == 8 && !currentInput.empty()) { // Backspace
                        currentInput.pop_back();
                    }
                    else if (event.text.unicode >= '0' && event.text.unicode <= '9') {
                        currentInput += static_cast<char>(event.text.unicode);
                    }
                    inputText.setString(currentInput);
                }
            }

            draw();
        }
    }
};
using namespace sf;
struct NodeG {
    CircleShape shape;
    Vector2f position;
    Text label;
    int id;
}
    ;
    // Edge structure
    struct Edge {
        Vertex line[2];
        int from;
        int to;
    }
    ;
    class BFSVisualizer {
    private:
        std::vector<NodeG> nodes;
        std::vector<Edge> edges;
        std::unordered_map<int, std::vector<int>> adjacencyList;
        Font font;
        Text infoText;
        Text instructionText;
        std::queue<int> bfsQueue;
        std::unordered_map<int, bool> visited;
        bool isBFSRunning = false;
        Vector2f originalSize{ 1200, 800 }; // Window size
        void initializeGraph() {
            // Create nodes in a more spread out pattern
            addNode(200, 200, "0");  // Node 0
            addNode(400, 200, "1");  // Node 1
            addNode(600, 200, "2");  // Node 2
            addNode(200, 400, "3");  // Node 3
            addNode(400, 400, "4");  // Node 4
            addNode(600, 400, "5");  // Node 5
            addNode(400, 600, "6");  // Node 6
            // Create edges to form a connected graph
            addEdge(0, 1);
            addEdge(1, 2);
            addEdge(0, 3);
            addEdge(1, 4);
            addEdge(2, 5);
            addEdge(3, 4);
            addEdge(4, 5);
            addEdge(3, 6);
            addEdge(4, 6);
        }
        void addNode(float x, float y, const std::string& label) {
            NodeG node;
            node.position = { x, y };
            node.shape.setRadius(30);
            node.shape.setFillColor(Color::White);
            node.shape.setOutlineColor(Color::Black);
            node.shape.setOutlineThickness(2);
            node.shape.setPosition(x - 30, y - 30);  // Center the circle on the position
            node.id = nodes.size();
            // Setup node label
            node.label.setFont(font);
            node.label.setString(label);
            node.label.setCharacterSize(20);
            node.label.setFillColor(Color::Black);
            node.label.setPosition(x - 10, y - 15);  // Center the text in the node
            nodes.push_back(node);
            adjacencyList[node.id] = {};
        }
        void addEdge(int from, int to) {
            Edge edge;
            edge.line[0].position = nodes[from].position;
            edge.line[1].position = nodes[to].position;
            edge.line[0].color = Color::Black;
            edge.line[1].color = Color::Black;
            edge.from = from;
            edge.to = to;
            edges.push_back(edge);
            // Add both directions for undirected graph
            adjacencyList[from].push_back(to);
            adjacencyList[to].push_back(from);
        }
        int getNodeAtPosition(Vector2i mousePos) {
            for (const auto& node : nodes) {
                float dx = mousePos.x - node.position.x;
                float dy = mousePos.y - node.position.y;
                if (dx * dx + dy * dy <= 30 * 30) {
                    return node.id;
                }
            }
            return -1;
        }
        void startBFS(int startNode) {
            // Reset all nodes to white
            for (auto& node : nodes) {
                node.shape.setFillColor(Color::White);
            }
            // Clear previous BFS data
            while (!bfsQueue.empty()) bfsQueue.pop();
            visited.clear();
            isBFSRunning = true;
            // Initialize BFS
            bfsQueue.push(startNode);
            visited[startNode] = true;
            nodes[startNode].shape.setFillColor(Color::Green);
        }
        void processBFS() {
            if (!bfsQueue.empty()) {
                int currentNode = bfsQueue.front();
                bfsQueue.pop();
                // Process all neighbors
                for (int neighbor : adjacencyList[currentNode]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        bfsQueue.push(neighbor);
                        nodes[neighbor].shape.setFillColor(Color::Green);
                    }
                }
                // Mark current node as processed
                nodes[currentNode].shape.setFillColor(Color::Blue);
            }
            else {
                isBFSRunning = false;
            }
        }
        void updateInfoText() {
            std::ostringstream oss;
            oss << "Nodes: " << nodes.size() << "\nQueue Size: " << bfsQueue.size();
            infoText.setString(oss.str());
        }
    public:
        BFSVisualizer() {
            if (!font.loadFromFile("art.ttf")) {  // Make sure you have this font file
                // Handle font loading error
                throw std::runtime_error("Failed to load font");
            }
            // Initialize info text
            infoText.setFont(font);
            infoText.setCharacterSize(20);
            infoText.setFillColor(Color::Black);
            infoText.setPosition(10, 10);
            // Initialize instruction text
            instructionText.setFont(font);
            instructionText.setString("Click on any node to start BFS");
            instructionText.setCharacterSize(20);
            instructionText.setFillColor(Color::Black);
            instructionText.setPosition(10, 50);
            initializeGraph();
        }
        void run() {
            RenderWindow window(VideoMode(1200, 800), "BFS Visualization");
            window.setFramerateLimit(60);
            while (window.isOpen()) {
                Event event;
                while (window.pollEvent(event)) {
                    if (event.type == Event::Closed)
                        window.close();
                    if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left) {
                        if (!isBFSRunning) {
                            int clickedNode = getNodeAtPosition(Mouse::getPosition(window));
                            if (clickedNode != -1) {
                                startBFS(clickedNode);
                            }
                        }
                    }
                }
                if (isBFSRunning) {
                    processBFS();
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));
                }
                updateInfoText();
                window.clear(Color::White);
                // Draw edges
                for (const auto& edge : edges) {
                    window.draw(edge.line, 2, Lines);
                }
                // Draw nodes and labels
                for (const auto& node : nodes) {
                    window.draw(node.shape);
                    window.draw(node.label);
                }
                // Draw UI elements
                window.draw(infoText);
                window.draw(instructionText);
                window.display();
            }
        }
    };
