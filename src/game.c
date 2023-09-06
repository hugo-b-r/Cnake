/*

    game.c
    Copyright (c) 2022 - 2023 Hugo Berthet-Rambaud

    This file is part of Cnake which is MIT licensed. It should be included
    with your copy of the code. See http://opensource.org/licenses/MIT.
 
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#include "game.h"
#include "positions.h"
#include "main.h"
#ifdef WINDOWS
    #include "windows.h"
#elif defined LINUX
    #include "linux.h"
#elif defined NUMWORKS || defined EPSILON_VERSION
    #include "numworks.h"
#endif



int tail_position(int head_position, int current_length)
{
    if (head_position == current_length - 1) {
        return 0;
    } else {
        return head_position + 1;
    }
}


void pause_loop(Control *control)
{   
    int playground_width = screen_x();
    print_at(playground_width/2-10, 0, "Pause - press any key");
    while (*control == holdon) {
        *control = get_control_blocking();
    }
    for (int i = playground_width/2-10; i < playground_width/2+11; i++) {
        draw_top_separator(i);
    }
}


void increase_snake_length(
    int (*positions)[2][100],
    int *current_length,
    int length_diff,
    int head_position
) {   
    for (int i = 0; i < ((*current_length) - head_position - 1); i++) {
        (*positions)[0][(*current_length) - i - 1 + length_diff] = (*positions)[0][(*current_length) - i - 1];
        (*positions)[1][(*current_length) - i - 1 + length_diff] = (*positions)[1][(*current_length) - i - 1];
    }
    (*current_length) += length_diff;
}


void game(
    int playground_width,
    int playground_height,
    int *game_continue
) {
    Orientation orientation = south;
    int level = 0;

    Control control = down;

    int current_length = DEFAULT_LENGTH;
    int positions[2][100];
    int head_position = current_length - 1;
    int assumed_length = level + DEFAULT_LENGTH;

    for (int i = 0; i < 100; i++) {
        positions[0][i] = -1;    
        positions[1][i] = -1; 
    }

    for (int i = 0; i < current_length; i++) {
        positions[0][i] = playground_width/2;
        positions[1][i] = playground_height/2;
        positions[1][i] -= current_length/2;
        positions[1][i] += i;      
    }

    srand(time(0));

    clear_screen();
    //fruit pos
    int fruit_x = rand() % (playground_width);
    int fruit_y = rand() % (playground_height);
    draw_sth (fruit_x, fruit_y+1, fruit_dr);


    // Print underscore line to show that the snake can't go on this line
    for(int i = 0; i < playground_width; i++) {
        draw_top_separator(i);
    }
    // Print score
    char str[9];
    sprintf(str, "%d", level); // Unsafe if too good at this game i.e. score too high
    print_at(0, 0, "Points: ");
    print_at(8, 0, str);



    while (control != end_game && control != quit) {
        
		control = get_control_non_blocking();
		switch(control) {
			case up:
                if (orientation != south) orientation = north;
                break;
			case left:
				if (orientation != east) orientation = west;
                break;
			case down:
				if (orientation != north) orientation = south;
                break;
			case right:
				if (orientation != west) orientation = east;
                break;
            case holdon:
                pause_loop(&control);
                break;
            case end_game:
                clear_screen();
                game_continue = 0;
                return;
                break;
			default:
				break;
		};

        if (fruit_x == positions[0][tail_position(head_position, current_length)] && fruit_y == positions[1][tail_position(head_position, current_length)]) {
            draw_sth(fruit_x, fruit_y+1, fruit_dr);
        } else {
            draw_sth(positions[0][tail_position(head_position, current_length)], positions[1][tail_position(head_position, current_length)]+1, nothing_dr);
        }
        // Compute the new position of the head
        int x = positions[0][head_position];
        int y = positions[1][head_position];
        // Convert orientation to coordinates change
        switch (orientation) {
        case north:
            y -= 1; // Remember coordinates are "reversed"
            break;
        case west:
            x -= 1; // i.e.
            break;
        case south:
            y += 1; // i.e.
            break;
        case east:
            x += 1; // i.e.
            break;
        }

        //if on itself
        for (int i = 0; i < current_length; i++) {
            if ( (x == positions[0][i]) && (y == positions[1][i]) ) {
                new_position_storage(&head_position, current_length, &positions, x, y);
                clear_screen();
                print_at(0, 0, "Ouch. You died eating yourself.");
                control = end_game;
                uni_sleep(1000);
                return; // Engame if new pos not good
            }
        }

        // if border
        if ( (x > (playground_width-1)) || (y > (playground_height-1)) || (x < 0) || (y < 0) ) {
            new_position_storage(&head_position, current_length, &positions, x, y);
            clear_screen();
            print_at(0, 0, "You died crushed against the wall.");
            control = end_game;
            uni_sleep(1000);
            return; // Engame if new pos not good
        } else {

            new_position_storage(&head_position, current_length, &positions, x, y);
            increase_position(&head_position, current_length);
        }
        draw_sth(positions[0][head_position], positions[1][head_position]+1, snake_body);

        //if on fruit
        if ((positions[0][head_position] == fruit_x) && (positions[1][head_position] == fruit_y)) {
            draw_sth(fruit_x, fruit_y+1, snake_body);
            fruit_x = rand() % (playground_width);
            fruit_y = rand() % (playground_height);
            draw_sth(fruit_x, fruit_y+1, fruit_dr);
            assumed_length++;
            increase_snake_length(&positions, &current_length, 1, head_position);
            level += 1;
            // Update the score
            // Print underscore line to show that the snake can't go on this line
            // Only for 9 because the score can't have more digits anyway.
            for(int i = 8; i < 18; i++) {
                draw_top_separator(i);
            }
            // Print score
            char str[9];
            sprintf(str, "%d", level); // Unsafe if too good at this game i.e. score too high
            print_at(8, 0, str);
    


        } else if (assumed_length > current_length) {
            increase_snake_length(&positions, &current_length, 1, head_position);
        }

        uni_sleep(DEFAULT_SPEED);
    }

    if (control == quit) *game_continue = 0;
}
