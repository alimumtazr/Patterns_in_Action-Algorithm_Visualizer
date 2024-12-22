<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Data Structures and Algorithms Visualizer</h1>  
    <p>An interactive educational tool for visualizing data structures and algorithms, designed for both students and educators. This project provides real-time animation of various algorithms and data structures, making complex concepts easier to understand.</p>
    <h2>🎯 Main Features</h2>
    <ul>
        <li>Data Structure-specific algorithm selection</li>
        <li>Random data generation for basic data structures</li>
        <li>Custom data input for advanced data structures</li>
        <li>Customizable visualization speed, colors, and sound effects</li>
        <li>Comprehensive operation selection for advanced data structures</li>
        <li>Time complexity analysis and performance monitoring</li>
        <li>End-to-end visualization of data structure operations</li>
    </ul>
    <h2>👥 Target Users</h2> 
    <h3>Students/Teachers/General Users</h3>
    <ul>
        <li>Algorithm selection based on specific data structures</li>
        <li>Custom/Random data loading options</li>
        <li>Interactive speed control</li>
        <li>Visual and audio feedback</li>
        <li>Detailed operation visualization</li>
    </ul>
    <h3>Developers</h3>
    <ul>
        <li>Access to modifiable codebase</li>
        <li>Extensible architecture for new algorithms</li>
        <li>Customizable visualization parameters</li>
    </ul>
    <h2>🔧 System Requirements</h2>
    <ul>
        <li>C++ compiler with C++11 support</li>
        <li>SFML Graphics Library</li>
        <li>Windows Operating System</li>
        <li>Minimum 4GB RAM</li>
        <li>Graphics card with basic 2D support</li>
    </ul>
    <h2>📊 Implementation Details</h2> 
    <h3>Sorting Algorithms Implementation</h3>
    <pre><code>// Bubble Sort (Complexity: O(n²))
void bubbleSort(sf::RenderWindow& window, std::vector<int>& array) {
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[j], array[j + 1]);
                drawArray(window, array, j, j + 1, false, false);
            }
        }
    }
}</code></pre>
    <h3>Binary Search Tree</h3>
    <pre><code>// BST Node Structure
struct NodeT {
    int value;
    NodeT* left;
    NodeT* right;
    float x, y; // Visualization coordinates
    NodeT(int val) : value(val), left(nullptr), right(nullptr), x(0), y(0) {}
};</code></pre>
    <h3>HashMap Implementation</h3>
    <pre><code>// HashMap Element Addition
void addElement(int key) {
    int bucketIndex = key % bucketCount;
    hashmap[bucketIndex].push_back(key);   
    sf::CircleShape element(20);
    element.setFillColor(sf::Color::Red);
    element.setPosition(470 + elements[bucketIndex].size() * 50,
                       210 + bucketIndex * 70);
    elements[bucketIndex].push_back(element);
}</code></pre>
    <h2>⚡ Performance Analysis</h2>
    <table>
        <tr>
            <th>Algorithm</th>
            <th>Data Structure</th>
            <th>Time Complexity</th>
            <th>Space Complexity</th>
        </tr>
        <tr>
            <td>Bubble Sort</td>
            <td>Array</td>
            <td>O(n²)</td>
            <td>O(1)</td>
        </tr>
        <tr>
            <td>Selection Sort</td>
            <td>Doubly Linked List</td>
            <td>O(n²)</td>
            <td>O(1)</td>
        </tr>
        <tr>
            <td>Insertion Sort</td>
            <td>Dynamic Stack & Array</td>
            <td>O(n²)</td>
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Merge Sort</td>
            <td>Array, Recursion</td>
            <td>O(n log n)</td>
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Quick Sort</td>
            <td>Array, Stack</td>
            <td>O(n log n)</td>
            <td>O(log n)</td>
        </tr>
        <tr>
            <td>BST Operations</td>
            <td>Binary Search Tree</td>
            <td>O(log n) average</td>
            <td>O(n)</td>
        </tr>
        <tr>
            <td>HashMap Operations</td>
            <td>Hash Table with Chaining</td>
            <td>O(1) average, O(n) worst</td>
            <td>O(n)</td>
        </tr>
        <tr>
            <td>Graph BFS</td>
            <td>Graph + Queue</td>
            <td>O(V + E)</td>
            <td>O(V)</td>
        </tr>
    </table>
    <h2>🎨 Visualization Features</h2>
    <ul>
        <li><strong>Basic Data Structures:</strong>
            <ul>
                <li>Real-time sorting animation</li>
                <li>Color-coded operations</li>
                <li>Performance timer</li>
                <li>Sound effects for operations</li>
            </ul>
        </li>
        <li><strong>Binary Search Tree:</strong>
            <ul>
                <li>Interactive node insertion/deletion</li>
                <li>Tree traversal visualization</li>
                <li>Dynamic node positioning</li>
            </ul>
        </li>
        <li><strong>HashMap:</strong>
            <ul>
                <li>Bucket-based collision handling</li>
                <li>Real-time element insertion</li>
                <li>Chain visualization</li>
            </ul>
        </li>
        <li><strong>Graph:</strong>
            <ul>
                <li>Interactive BFS traversal</li>
                <li>Color-coded node states</li>
                <li>Edge visualization</li>
            </ul>
        </li>
    </ul>
    <h2>📁 Project Structure</h2>
    <ul>
        <li>Source files (*.cpp)</li>
        <li>SFML headers</li>
        <li>Resource files:
            <ul>
                <li>Sound effects (*.wav)</li>
                <li>Textures (*.png)</li>
                <li>Fonts (*.ttf)</li>
            </ul>
        </li>
    </ul>
    <h2>🤝 Contributing</h2>
    <p>Contributions are welcome! Feel free to:</p>
    <ul>
        <li>Add new algorithms</li>
        <li>Improve visualizations</li>
        <li>Enhance performance</li>
        <li>Fix bugs</li>
        <li>Add documentation</li>
    </ul>
    <h2>📝 License</h2>
    <p>This project is licensed under the MIT License - see the LICENSE file for details</p>
    <hr>
    <p align="center">Made with ❤️ for algorithm enthusiasts and computer science students</p>
</body>
</html>
