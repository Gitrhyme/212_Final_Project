#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <random>
#include <unistd.h>

unsigned int microsecond = 1000;

std::vector<int> vect()
{
    std::random_device rd;
    std::uniform_int_distribution<int> ud(1, 80 / 2);
    std::vector<int> v;
    for (int i = 0; i < 75; i++)
    {
        v.push_back(ud(rd));
    }
    return v;
}

void draw_state(std::vector<int> &v, std::vector<sf::RectangleShape> &bars, int red, int blue, sf::RenderWindow &window)
{
    usleep(microsecond * 20);
    window.clear();
    for (int i = 0; i < bars.size(); i++)
    {
        int random_height = v[i];
        sf::RectangleShape bb = bars[i];
        if (i == red)
        {
            bb.setSize(sf::Vector2f(10.0, -random_height * 20));
            bb.setFillColor(sf::Color(255, 0, 0));
        }
        if (i == blue)
        {
            bb.setSize(sf::Vector2f(10.0, -random_height * 20));
            bb.setFillColor(sf::Color(0, 0, 255));
        }
        else
        {

            bb.setSize(sf::Vector2f(10.0, -random_height * 20));
            bb.setFillColor(sf::Color(255, 255, 255));
        }
        window.draw(bb);
    }
    window.display();
}

int partition(std::vector<int> &list, int low, int high, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    int pivot = list[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (list[j] < pivot)
        {
            i++;
            std::swap(list[i], list[j]);
        }
        draw_state(list, bars, low, high, window);
    }
    std::swap(list[i + 1], list[high]);
    return i + 1;
}

void Quicksort(std::vector<int> &list, int low, int high, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    if (low < high)
    {
        int part = partition(list, low, high, window, bars);
        Quicksort(list, low, part - 1, window, bars);
        Quicksort(list, part + 1, high, window, bars);
    }
}

void final_merge(std::vector<int> &list, std::vector<int> left, std::vector<int> right, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    int left_size = left.size();
    int right_size = right.size();

    int left_idx = 0, right_idx = 0, list_idx = 0;

    while (left_idx < left_size && right_idx < right_size)
    {
        if (left[left_idx] <= right[right_idx])
        {
            list[list_idx] = left[left_idx];
            left_idx++;
        }
        else
        {
            list[list_idx] = right[right_idx];
            right_idx++;
        }
        draw_state(list, bars, left_idx, right_idx, window);
        list_idx++;
    }
    while (left_idx < left_size)
    {
        list[list_idx] = left[left_idx];
        left_idx++;
        list_idx++;
    }
    while (right_idx < right_size)
    {
        list[list_idx] = right[right_idx];
        right_idx++;
        list_idx++;
    }
}

void merge_sort(std::vector<int> &list, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    int list_size = list.size();
    // There is only one element
    if (list_size < 2)
    {
        return;
    }
    // Split elements_list in half as left and right
    int middle = list_size / 2;
    std::vector<int> left;
    std::vector<int> right;
    // Fill left and right
    for (int i = 0; i < middle; i++)
    {
        left.push_back(list[i]);
    }
    for (int i = middle; i < list_size; i++)
    {
        right.push_back(list[i]);
    }

    merge_sort(left, window, bars);
    merge_sort(right, window, bars);
    final_merge(list, left, right, window, bars);
}

void InsertionSort(std::vector<int> &v, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    for (int i = 1; i < v.size(); i++)
    {
        int j = i - 1;
        int x = v[i];
        while (j > -1 && v[j] > x)
        {
            v[j + 1] = v[j];
            j--;
        }
        draw_state(v, bars, i, j, window);
        v[j + 1] = x;
    }
}

void SelectionSort(std::vector<int> &v, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        for (unsigned int j = i; j < v.size(); j++)
        {

            if (v[j] < v[i])
            {
                std::swap(v[j], v[i]);
            }

            draw_state(v, bars, i, j, window);
        }
    }
}

void BubbleSort(std::vector<int> &v, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{

    for (int i = 0; i < v.size() - 1; i++)
    {

        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                std::swap(v[j], v[j + 1]);
            }
            draw_state(v, bars, i, j, window);
        }
    }
}

std::vector<sf::RectangleShape> barVector(std::vector<int> v, int height)
{
    std::vector<sf::RectangleShape> bars;
    for (int i = 0; i < v.size(); ++i)
    {
        sf::RectangleShape rect;
        // shift each bar to the right
        int xPos = 10 + (10 * i * 2);
        int yPos = (height * .999f);
        rect.setPosition(xPos, yPos);
        bars.push_back(rect);
    }
    return bars;
}

void Initial_and_Final_Print(std::vector<int> &v, sf::RenderWindow &window, std::vector<sf::RectangleShape> &bars)
{
    // DRAW RECTANGLES (Initial and Final draw states)
    window.clear();
    for (int i = 0; i < bars.size(); i++)
    {
        int random_height = v[i];
        sf::RectangleShape bb = bars[i];
        bb.setSize(sf::Vector2f(10.0, -random_height * 20));
        bb.setFillColor(sf::Color(255, 255, 255));
        window.draw(bb);
    }
    window.display();
}

void App()
{
    int height = 1000;
    int width = 1500;

    // Randomized Vector of Ints
    std::vector<int> v = vect();
    // Vector of Bars that will be displayed
    std::vector<sf::RectangleShape> bars = barVector(v, height);

    // Create Window
    sf::RenderWindow window(sf::VideoMode(width, height), "Sorting App");

    // Track Window Events
    sf::Event e;

    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            // MANUALLY CLOSE WINDOW
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
            // Button Calls
            if (e.type == sf::Event::KeyReleased)
            {
                // Hit 0 for New Vector
                if (e.key.code == sf::Keyboard::Num0)
                {
                    v = vect();
                    bars = barVector(v, height);
                }
                // Hit 1 for Bubble
                if (e.key.code == sf::Keyboard::Num1)
                {
                    BubbleSort(v, window, bars);
                }
                // Hit 2 to for Insertion
                if (e.key.code == sf::Keyboard::Num2)
                {
                    InsertionSort(v, window, bars);
                }
                // Hit 3 for Merge
                if (e.key.code == sf::Keyboard::Num3)
                {
                    merge_sort(v, window, bars);
                }
                // Hit 4 for Quick
                if (e.key.code == sf::Keyboard::Num4)
                {
                    Quicksort(v, 0, v.size() - 1, window, bars);
                }
                // Hit 5 for Selection
                if (e.key.code == sf::Keyboard::Num5)
                {
                    SelectionSort(v, window, bars);
                }
            }
        }
        Initial_and_Final_Print(v, window, bars);
    }
}

int main()
{
    std::cout << "There are 5 sorting algorithms you can visualize in this program." << std::endl
              << std::endl;
    std::cout << "To Run:" << std::endl
              << std::endl;
    std::cout << "Hit 0 for New Vector" << std::endl
              << std::endl;
    std::cout << "Hit 1 for Bubble Sort" << std::endl
              << std::endl;
    std::cout << "Hit 2 for Insertion Sort" << std::endl
              << std::endl;
    std::cout << "Hit 3 for Merge Sort" << std::endl
              << std::endl;
    std::cout << "Hit 4 for Quick Sort" << std::endl
              << std::endl;
    std::cout << "Hit 5 for Selection Sort" << std::endl
              << std::endl;
    std::cout << "PRESS ANY KEY TO CONTINUE..." << std::endl;
    // Pause Program to allow for directional read (may need to switch "read" to "pause" for Windows users)
    system("read");

    // RUN APP
    App();

    return 0;
}