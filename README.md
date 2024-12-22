<!DOCTYPE html>
<html lang="en">
<head>

<h1>Sorting Algorithms Visualization</h1>

<p>This project implements various sorting algorithms using different data structures, providing a visual representation of the sorting process. The primary focus is on the utilization of data structures such as arrays, linked lists, trees, and hashmaps, showcasing their roles in sorting and data management.</p>

<h2>Table of Contents</h2>
<ul>
    <li><a href="#introduction">Introduction</a></li>
    <li><a href="#data-structures-used">Data Structures Used</a></li>
    <li><a href="#sorting-algorithms-implemented">Sorting Algorithms Implemented</a></li>
    <li><a href="#visualization">Visualization</a></li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#contributing">Contributing</a></li>
</ul>

<h2 id="introduction">Introduction</h2>
<p>Sorting algorithms are fundamental in computer science, and understanding their mechanics is crucial for optimizing performance in various applications. This project not only implements sorting algorithms but also visualizes the process, making it easier to grasp how different data structures affect the sorting performance and behavior.</p>

<h2 id="data-structures-used">Data Structures Used</h2>
<ol>
    <li><strong>Arrays</strong>: 
        <ul>
            <li>Used in Bubble Sort, Merge Sort, Insertion Sort, Selection Sort, and Quick Sort.</li>
            <li>Provides a simple and efficient way to store and access elements.</li>
        </ul>
    </li>
    <li><strong>Doubly Linked Lists</strong>:
        <ul>
            <li>Implemented in Selection Sort.</li>
            <li>Allows for efficient insertion and deletion of nodes, showcasing how linked lists can be used to manage data dynamically.</li>
        </ul>
    </li>
    <li><strong>Binary Search Trees (BST)</strong>:
        <ul>
            <li>Used to visualize the insertion and deletion of nodes.</li>
            <li>Demonstrates how tree structures can maintain sorted data and allow for efficient searching.</li>
        </ul>
    </li>
    <li><strong>Hashmaps</strong>:
        <ul>
            <li>Visualized to demonstrate how data can be stored and accessed using key-value pairs.</li>
            <li>Provides insight into collision handling and the efficiency of hash-based data storage.</li>
        </ul>
    </li>
    <li><strong>Graphs</strong>:
        <ul>
            <li>Visualized using BFS (Breadth-First Search) to demonstrate graph traversal.</li>
            <li>Shows how nodes and edges can represent relationships and connections in data.</li>
        </ul>
    </li>
</ol>

<h2 id="sorting-algorithms-implemented">Sorting Algorithms Implemented</h2>
<ol>
    <li><strong>Bubble Sort</strong>: A simple comparison-based algorithm that repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order.</li>
    <li><strong>Merge Sort</strong>: A divide-and-conquer algorithm that divides the array into halves, sorts them, and then merges them back together.</li>
    <li><strong>Insertion Sort</strong>: Builds a sorted array one element at a time by repeatedly taking an element from the unsorted part and inserting it into the correct position in the sorted part.</li>
    <li><strong>Selection Sort</strong>: Divides the input list into two parts: 
<h2 id="visualization">Visualization</h2>
<p>The visualization is implemented using the SFML (Simple and Fast Multimedia Library) framework, allowing for real-time graphical representation of the sorting processes. Each algorithm's steps are displayed, highlighting the elements being compared and swapped, as well as the structure of the data being manipulated.</p>

<h3>Key Features:</h3>
<ul>
    <li>Real-time visualization of sorting algorithms.</li>
    <li>Interactive elements to pause, resume, and close the visualization.</li>
    <li>Graphical representation of data structures (e.g., trees, linked lists, hashmaps).</li>
</ul>

<h2 id="usage">Usage</h2>
<p>To run the project, ensure you have the SFML library installed. Compile the code and execute the program. You can interact with the visualization by clicking buttons to start the sorting process and observe how different data structures are manipulated.</p>

<h3>Example Commands:</h3>
<pre><code>
# Compile the project
g++ -o sorting_visualization main.cpp -lsfml-graphics -lsfml-window -lsfml-system

# Run the visualization
./sorting_visualization
</code></pre>

<h2 id="contributing">Contributing</h2>
<p>Contributions are welcome! If you have suggestions for improvements or additional features, feel free to open an issue or submit a pull request.</p>


</body>
</html>
