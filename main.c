#include <stdio.h>
#include <math.h>
#define kSize 24
#define pi 3.14

void Circle(int);
void Triangle(int, int);

int main()
{
    int input_number = 0, counter = 0;
    int triangle_count = 0;
    while (1)
    {
        printf("Choose a geometric shape: 1 - circle, 2 - triangle, 0 - exit\n");
        scanf("%d", &input_number);
        if (input_number == 1)
        {
            counter++;
            Circle(counter);
        }
        if (input_number == 2)
        {
            counter++;
            Triangle(counter, triangle_count);
            triangle_count += 6;
        }
        if (input_number == 0)
        {
            break;
        }
    }
}

void Circle(int counter)
{
    float input_radius = 0, perimeter = 0, area = 0;
    printf("Radius = ");
    scanf("%f", &input_radius);
    perimeter = 2 * input_radius * pi;
    area = pi * input_radius * input_radius;
    printf("Perimeter of %d shape (circle): %f\n", counter, perimeter);
    printf("Area of %d shape (circle): %f\n", counter, area);
}

void Triangle(int counter, int triangle_count)
{
    float perimeter = 0, side_a = 0, side_b = 0, side_c = 0, area = 0, semi_per = 0;
    float triangle_points[kSize] = { 0 };
    for (int i = 0; i < 6; i++)
    {
        float input_coordinate = 0;
        if (i % 2 == 0)
        {
            printf("X: ");
            scanf("%f", &input_coordinate);
            triangle_points[i + triangle_count] = input_coordinate;
        }
        if (i % 2 == 1)
        {
            printf("Y: ");
            scanf("%f", &input_coordinate);
            triangle_points[i + triangle_count] = input_coordinate;
        }
    }
    side_a = sqrt(powf(triangle_points[triangle_count] - triangle_points[triangle_count + 2], 2) + powf(triangle_points[triangle_count + 1] - triangle_points[triangle_count + 2], 2));
    side_b = sqrt(powf(triangle_points[triangle_count] - triangle_points[triangle_count + 4], 2) + powf(triangle_points[triangle_count + 1] - triangle_points[triangle_count + 5], 2));
    side_c = sqrt(powf(triangle_points[triangle_count + 2] - triangle_points[triangle_count + 4], 2) + powf(triangle_points[triangle_count + 3] - triangle_points[triangle_count + 5], 2));
    perimeter = side_a + side_b + side_c;
    semi_per = perimeter / 2;
    area = sqrt(semi_per * (semi_per - side_a) * (semi_per - side_b) * (semi_per - side_c));
    printf("Perimeter of %d shape (triangle): %f\n", counter, perimeter);
    printf("Area of %d shape (triangle): %f\n", counter, area);
}
