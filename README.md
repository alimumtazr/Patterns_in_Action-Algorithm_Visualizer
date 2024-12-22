<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
</head>
<body>
    <h1>Data Structures and Algorithms Visualizer</h1> 
    <p>An interactive visualization tool for various data structures and algorithms implemented using SFML graphics library. This project helps in understanding the inner workings of different algorithms and data structures through visual representation.</p>
    <h2>🚀 Features</h2>
    <ul>
        <li><strong>Sorting Algorithms</strong>
            <ul>
                <li>Bubble Sort</li>
                <li>Merge Sort</li>
                <li>Quick Sort</li>
                <li>Insertion Sort</li>
                <li>Selection Sort</li>
            </ul>
        </li>
        <li><strong>Data Structures</strong>
            <ul>
                <li>Binary Search Tree (BST)</li>
                <li>Hash Map</li>
                <li>Graph (with BFS visualization)</li>
            </ul>
        </li>
    </ul>
    <h2>🛠️ Technologies Used</h2>
    <ul>
        <li>C++</li>
        <li>SFML (Simple and Fast Multimedia Library)</li>
        <li>Standard Template Library (STL)</li>
    </ul>
    <h2>🔧 Installation</h2>
    <ol>
        <li>Clone the repository:
            <pre><code>git clone https://github.com/yourusername/dsa-visualizer.git</code></pre>
        </li>
        <li>Install SFML:
            <pre><code>sudo apt-get install libsfml-dev  # For Ubuntu/Debian
brew install sfml            # For macOS</code></pre>
        </li>
        <li>Build the project:
            <pre><code>cd dsa-visualizer
make</code></pre>
        </li>
    </ol>
    <h2>💻 Usage</h2>
    <p>The program provides different visualizations:</p>
    <h3>Sorting Visualizer</h3>
    <ul>
        <li>Bars represent array elements</li>
        <li>Height of bars indicates the value</li>
        <li>Color changes show the comparison and swapping operations</li>
    </ul>
    <h3>Binary Search Tree</h3>
    <ul>
        <li>Nodes are displayed as circles with values</li>
        <li>Tree structure shows parent-child relationships</li>
        <li>Red nodes indicate the current operation</li>
    </ul>
    <h3>HashMap Visualization</h3>
    <ul>
        <li>Shows bucket structure and collision handling</li>
        <li>Interactive insertion of elements</li>
        <li>Visual representation of chaining</li>
    </ul>
    <h3>Graph BFS Visualization</h3>
    <ul>
        <li>Interactive node-based graph structure</li>
        <li>Color-coded BFS traversal</li>
        <li>Queue size and visited nodes tracking</li>
    </ul>
    <h2>🎯 Code Examples</h2>
    <h3>Drawing Array Elements:</h3>
    <pre><code>bar.setPosition(i * BAR_WIDTH + 50, WINDOW_HEIGHT - array[i] + 50);
window.draw(bar);</code></pre>
    <h3>BST Node Structure:</h3>
    <pre><code>struct NodeT {
    int value;
    NodeT* left;
    NodeT* right;
    float x, y; // Position for visualization
    NodeT(int val) : value(val), left(nullptr), right(nullptr), x(0), y(0) {}
};</code></pre>
    <h2>🤝 Contributing</h2>
    <ol>
        <li>Fork the repository</li>
        <li>Create your feature branch (<code>git checkout -b feature/AmazingFeature</code>)</li>
        <li>Commit your changes (<code>git commit -m 'Add some AmazingFeature'</code>)</li>
        <li>Push to the branch (<code>git push origin feature/AmazingFeature</code>)</li>
        <li>Open a Pull Request</li>
    </ol>
    <h2>📝 License</h2>
    <p>This project is licensed under the MIT License - see the LICENSE file for details</p>
    <h2>✨ Acknowledgments</h2>
    <ul>
        <li>SFML Documentation and Community</li>
        <li>Algorithm Visualization Inspiration: VisuAlgo</li>
    </ul>
    <hr>
    <p align="center">Made with ❤️ for algorithm enthusiasts</p>
</body>
</html>
