#define is_down(b) input->buttons[b].is_down
#define pressed(b) (input->buttons[b].changed)
#define released(b) (!input->buttons[b].is_down && input->buttons[b].changed)
#include <stdlib.h>
#include <time.h>
#include "windows.h"
#include "math.h"

float player_1_p, player_1_dp, player_2_p, player_2_dp;
float arena_half_size_x = 85, arena_half_size_y = 45;
float player_half_size_x = 2.5, player_half_size_y = 12;
float ball_p_x, ball_p_y, ball_dp_x = 100, ball_dp_y, ball_half_size = 1;
float sdp = 50;

float spinner_half_size_1_x = 2.5;
float spinner_half_size_1_y = 8;

float spinner_half_size_2_x = 8;
float spinner_half_size_2_y = 2.5;


int score_1 = 0, score_2 = 0, game_score_1 = 0, game_score_2 = 0;

int color = 0, color_2 = 0;

bool pause = false;

bool start = false;


// displays scoreboard

internal void
simulate_score() {
	// displays left side scores 1-5
	switch (score_1) { 
		case 0:
			draw_rect(-22, 42, 4, 1, 0xfffffff); 
			draw_rect(-25, 35, 1, 6, 0xfffffff); 
			draw_rect(-22, 28, 4, 1, 0xfffffff); 
			draw_rect(-19, 35, 1, 6, 0xfffffff); 
			break;
		case 1:
			draw_rect(-20, 42, 1, 1, 0xfffffff); 
			draw_rect(-20, 28, 1, 1, 0xfffffff); 
			draw_rect(-16, 28, 1, 1, 0xfffffff); 
			draw_rect(-18, 35, 1, 8, 0xfffffff); 
			break;
		case 2:
			draw_rect(-18, 42, 4, 1, 0xfffffff); 
			draw_rect(-14, 39, 1, 4, 0xfffffff); 
			draw_rect(-18, 36, 4, 1, 0xfffffff); 
			draw_rect(-21, 33, 1, 4, 0xfffffff); 
			draw_rect(-17.5, 28, 4.5, 1, 0xfffffff); 
			break;
		case 3:
			draw_rect(-18, 42, 4, 1, 0xfffffff); 
			draw_rect(-14, 39, 1, 4, 0xfffffff); 
			draw_rect(-18, 35, 4, 1, 0xfffffff); 
			draw_rect(-14, 33, 1, 4, 0xfffffff); 
			draw_rect(-17.5, 28, 4.5, 1, 0xfffffff);
			break;
		case 4:
			draw_rect(-14, 39, 1, 4, 0xfffffff); 
			draw_rect(-18, 36, 4, 1, 0xfffffff); 
			draw_rect(-21, 39, 1, 4, 0xfffffff); 
			draw_rect(-14, 31, 1, 4, 0xfffffff); 
			break;
		case 5:
			draw_rect(-17, 42, 4, 1, 0xfffffff);
			draw_rect(-21, 39, 1, 4, 0xfffffff);
			draw_rect(-18, 36, 4, 1, 0xfffffff);
			draw_rect(-14, 33, 1, 4, 0xfffffff);
			draw_rect(-17.5, 28, 4.5, 1, 0xfffffff);
			break;
	}
	// displays right side scores 1-5
	switch (score_2) {
		case 0:
			draw_rect(22, 42, 4, 1, 0xfffffff); 
			draw_rect(25, 35, 1, 6, 0xfffffff); 
			draw_rect(22, 28, 4, 1, 0xfffffff); 
			draw_rect(19, 35, 1, 6, 0xfffffff); 
			break;
		case 1:
			draw_rect(16, 42, 1, 1, 0xfffffff); 
			draw_rect(20, 28, 1, 1, 0xfffffff); 
			draw_rect(16, 28, 1, 1, 0xfffffff); 
			draw_rect(18, 35, 1, 8, 0xfffffff); 
			break;
		case 2:
			draw_rect(18, 42, 4, 1, 0xfffffff); 
			draw_rect(22, 39, 1, 4, 0xfffffff); 
			draw_rect(18, 36, 4, 1, 0xfffffff); 
			draw_rect(15, 33, 1, 4, 0xfffffff); 
			draw_rect(18.5, 28, 4.5, 1, 0xfffffff); 
			break;
		case 3:
			draw_rect(18, 42, 4, 1, 0xfffffff); 
			draw_rect(22, 39, 1, 4, 0xfffffff); 
			draw_rect(18, 35, 4, 1, 0xfffffff); 
			draw_rect(22, 33, 1, 4, 0xfffffff); 
			draw_rect(18.5, 28, 4.5, 1, 0xfffffff); 
			break;
		case 4:
			draw_rect(14, 39, 1, 4, 0xfffffff); 
			draw_rect(18, 36, 4, 1, 0xfffffff); 
			draw_rect(21, 39, 1, 4, 0xfffffff); 
			draw_rect(21, 31, 1, 4, 0xfffffff); 
			break;
		case 5:
			draw_rect(18, 42, 4, 1, 0xfffffff); 
			draw_rect(14, 39, 1, 4, 0xfffffff); 
			draw_rect(18, 36, 4, 1, 0xfffffff); 
			draw_rect(21, 33, 1, 4, 0xfffffff); 
			draw_rect(17.5, 28, 4.5, 1, 0xfffffff); 
			break;
	}


}

internal void
simulate_game_score() {
	switch (game_score_1) {
	case 0:
		draw_rect(-90.5, 42, 4, 1, 0xfffffff);
		draw_rect(-93.5, 35, 1, 6, 0xfffffff);
		draw_rect(-90.5, 28, 4, 1, 0xfffffff);
		draw_rect(-87.5, 35, 1, 6, 0xfffffff);
		break;
	case 1:
		draw_rect(-92, 42, 1, 1, 0xfffffff);
		draw_rect(-92, 28, 1, 1, 0xfffffff);
		draw_rect(-88, 28, 1, 1, 0xfffffff);
		draw_rect(-90, 35, 1, 8, 0xfffffff);
		break;
	case 2:
		draw_rect(-91, 42, 4, 1, 0xfffffff);
		draw_rect(-87, 39, 1, 4, 0xfffffff);
		draw_rect(-91, 36, 4, 1, 0xfffffff);
		draw_rect(-94, 33, 1, 4, 0xfffffff);
		draw_rect(-90.5, 28, 4.5, 1, 0xfffffff);
		break;
	case 3:
		draw_rect(-91, 42, 4, 1, 0xfffffff);
		draw_rect(-87, 39, 1, 4, 0xfffffff);
		draw_rect(-91, 35, 4, 1, 0xfffffff);
		draw_rect(-87, 33, 1, 4, 0xfffffff);
		draw_rect(-90.5, 28, 4.5, 1, 0xfffffff);
		break;
	case 4:
		draw_rect(-87, 39, 1, 4, 0xfffffff);
		draw_rect(-91, 36, 4, 1, 0xfffffff);
		draw_rect(-94, 39, 1, 4, 0xfffffff);
		draw_rect(-87, 31, 1, 4, 0xfffffff);
		break;
	case 5:
		draw_rect(-90, 42, 4, 1, 0xfffffff);
		draw_rect(-94, 39, 1, 4, 0xfffffff);
		draw_rect(-91, 36, 4, 1, 0xfffffff);
		draw_rect(-87, 33, 1, 4, 0xfffffff);
		draw_rect(-90.5, 28, 4.5, 1, 0xfffffff);
		break;
	}
	// displays right side scores 1-5
	switch (game_score_2) {
	case 0:
		draw_rect(90.5, 42, 4, 1, 0xfffffff);
		draw_rect(93.5, 35, 1, 6, 0xfffffff);
		draw_rect(90.5, 28, 4, 1, 0xfffffff);
		draw_rect(87.5, 35, 1, 6, 0xfffffff);
		break;
	case 1:
		draw_rect(88, 42, 1, 1, 0xfffffff);
		draw_rect(92, 28, 1, 1, 0xfffffff);
		draw_rect(88, 28, 1, 1, 0xfffffff);
		draw_rect(90, 35, 1, 8, 0xfffffff);
		break;
	case 2:
		draw_rect(90, 42, 4, 1, 0xfffffff);
		draw_rect(94, 39, 1, 4, 0xfffffff);
		draw_rect(91, 36, 4, 1, 0xfffffff);
		draw_rect(87, 33, 1, 4, 0xfffffff);
		draw_rect(90.5, 28, 4.5, 1, 0xfffffff);
		break;
	case 3:
		draw_rect(90, 42, 4, 1, 0xfffffff);
		draw_rect(94, 39, 1, 4, 0xfffffff);
		draw_rect(90, 35, 4, 1, 0xfffffff);
		draw_rect(94, 33, 1, 4, 0xfffffff);
		draw_rect(90.5, 28, 4.5, 1, 0xfffffff);
		break;
	case 4:
		draw_rect(87, 39, 1, 4, 0xfffffff);
		draw_rect(91, 36, 4, 1, 0xfffffff);
		draw_rect(94, 39, 1, 4, 0xfffffff);
		draw_rect(94, 31, 1, 4, 0xfffffff);
		break;
	case 5:
		draw_rect(91, 42, 4, 1, 0xfffffff);
		draw_rect(87, 39, 1, 4, 0xfffffff);
		draw_rect(91, 36, 4, 1, 0xfffffff);
		draw_rect(94, 33, 1, 4, 0xfffffff);
		draw_rect(90.5, 28, 4.5, 1, 0xfffffff);
		break;
	}
}

// includes the physics engine for the paddles
// and handles collisions with the arena 


internal void
simulate_player(float *p, float *dp, float ddp, float dt) {
	ddp -= *dp * 10.f; // player acceleration equation

	*p = *p + *dp * dt + ddp * dt * dt * .5f; // player position equation
	*dp = *dp + ddp * dt; // player velocity equation

	if (*p + player_half_size_y > arena_half_size_y) { // player collision with top of arena
		*p = arena_half_size_y - player_half_size_y;
		*dp = 0;
	}
	else if (*p - player_half_size_y < -arena_half_size_y) { // player collision with bottom of arena 
		*p = -arena_half_size_y + player_half_size_y;
		*dp = 0;
	}
}

internal void
spinner_state_1_collision() {
	if (ball_p_x + ball_half_size > 40 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > -29 - (2 + spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < -29 + (2 + spinner_half_size_1_y)) {
		ball_p_x = 40 - spinner_half_size_1_x - ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_x *= -1;
		ball_dp_y += 5; 
	}


	else if (ball_p_x + ball_half_size > 41.25 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < 41.25 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > -29 - (2 + spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < -29 + (2 + spinner_half_size_1_y)) {
		ball_p_x = 41.25 + player_half_size_x + ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_y += 5; 
	}


	if (ball_p_x + ball_half_size > -40 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > 32 - (spinner_half_size_1_y + 2) &&
		ball_p_y + ball_half_size < 32 + (spinner_half_size_1_y)) {
		ball_p_x = -40 + spinner_half_size_1_x + ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_y += 5; 
	}


	else if (ball_p_x + ball_half_size > -41.25 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < -41.25 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > 31 - (spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < 32 + (spinner_half_size_1_y)) {
		ball_p_x = -41.25 - player_half_size_x - ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_x *= -1;
		ball_dp_y += 5;
	}
}

internal void
spinner_state_2_collision() {
	// side collisions

	if (ball_p_y >= -32.5 && ball_p_y <= -27 &&
		ball_p_x + ball_half_size > 40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 - spinner_half_size_2_x) {
		ball_p_x = 40 - spinner_half_size_2_x - ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_x *= -1;
	}

	else if (ball_p_y >= -32.5 && ball_p_y <= -27 &&
		ball_p_x + ball_half_size > 40 + spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_2_x) {
		ball_p_x = 40 + spinner_half_size_2_x + ball_half_size;
		ball_dp_x = rand() & 150 + 100;
	}

	if (ball_p_y <= 32.5 && ball_p_y >= 27 &&
		ball_p_x + ball_half_size > -40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 - spinner_half_size_2_x) {
		ball_p_x = -40 - spinner_half_size_2_x - ball_half_size;
		ball_dp_x = rand() % 150 + 100;
		ball_dp_x *= -1;
	}

	else if (ball_p_y <= 32.5 && ball_p_y >= 27 &&
		ball_p_x + ball_half_size > -40 + spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_2_x) {
		ball_p_x = -40 + spinner_half_size_2_x + ball_half_size;
		ball_dp_x = rand() & 150 + 100;
	}

	// top and bottom collisions

	if (ball_p_x + ball_half_size > 40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > -28.5 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < -28.5 + spinner_half_size_2_y) {
		ball_p_y = -28.5 + spinner_half_size_2_x + ball_half_size;
		ball_dp_y = rand() % 150 + 100;
	}

	else if (ball_p_x + ball_half_size > 40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > -30 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < -30 + spinner_half_size_2_y) {
		ball_p_y = -30 - spinner_half_size_2_x - ball_half_size;
		ball_dp_y = rand() % 150 + 100;
		ball_dp_y *= -1;
	}

	if (ball_p_x + ball_half_size > -40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > 28.5 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < 28.5 + spinner_half_size_2_y) {
		ball_p_y = 28.5 - spinner_half_size_2_x - ball_half_size;
		ball_dp_y = rand() % 150 + 100;
		ball_dp_y *= -1;
	}

	else if (ball_p_x + ball_half_size > -40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > 30 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < 30 + spinner_half_size_2_y) {
		ball_p_y = 30 + spinner_half_size_2_x + ball_half_size;
		ball_dp_y = rand() % 150 + 100;
	}
}

internal void
spinner_state_1_teleporter() {
	if (ball_p_x + ball_half_size > 40 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > -29 - (2 + spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < -29 + (2 + spinner_half_size_1_y)) {
		ball_p_x = -40 + spinner_half_size_1_x + ball_half_size;
		ball_p_y = 30;
		ball_dp_x += 5;
	}


	else if (ball_p_x + ball_half_size > 41.25 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < 41.25 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > -29 - (2 + spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < -29 + (2 + spinner_half_size_1_y)) {
		ball_p_x = -45;
		ball_p_y = 30;	
		ball_dp_x -= 5;
	}


	if (ball_p_x + ball_half_size > -40 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > 32 - (spinner_half_size_1_y + 2) &&
		ball_p_y + ball_half_size < 32 + (spinner_half_size_1_y)) {
		ball_p_x = 40 - spinner_half_size_1_x - ball_half_size;
		ball_p_y = -30;
		ball_dp_x += 5;
	}


	else if (ball_p_x + ball_half_size > -41.25 - spinner_half_size_1_x &&
		ball_p_x - ball_half_size < -41.25 + spinner_half_size_1_x &&
		ball_p_y + ball_half_size > 31 - (spinner_half_size_1_y) &&
		ball_p_y + ball_half_size < 32 + (spinner_half_size_1_y)) {
		ball_p_x = 45;
		ball_p_y = -30;
		ball_dp_x -= 5;
	}
} 

internal void
spinner_state_2_teleporter() {
	if (ball_p_x + ball_half_size > 40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > -28.5 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < -28.5 + spinner_half_size_2_y) {
		ball_p_y = 25;
		ball_p_x = -40;
		ball_dp_y -= 5;
		ball_dp_x += 5;
	}

	else if (ball_p_x + ball_half_size > 40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < 40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > -30 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < -30 + spinner_half_size_2_y) {
		ball_p_y = 33;
		ball_p_x = -40;
		ball_dp_y += 5;
		ball_dp_x += 5;
	}

	if (ball_p_x + ball_half_size > -40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > 28.5 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < 28.5 + spinner_half_size_2_y) {
		ball_p_y = -25.5;
		ball_p_x = 40;
		ball_dp_y += 5;
		ball_dp_x -= 5;
	}

	else if (ball_p_x + ball_half_size > -40 - spinner_half_size_2_x &&
		ball_p_x - ball_half_size < -40 + spinner_half_size_2_x &&
		ball_p_y + ball_half_size > 30 - spinner_half_size_2_y &&
		ball_p_y + ball_half_size < 30 + spinner_half_size_2_y) {
		ball_p_y = -33;
		ball_p_x = 40;
		ball_dp_y -= 5;
		ball_dp_x -= 5;
	}
}

// main function
// handles ball physics, player movement, and rendering

internal void 
simulate_game(Input* input, float dt) {
	//color += (int)rand() % INT_MAX;
	//color_2 += (int)rand() % INT_MAX;

	// title screen

	if (pause == false) {
		clock_t t;
		t = clock();
		if (t / CLOCKS_PER_SEC % 1 >= 0 && t / CLOCKS_PER_SEC % 2 <= 0.5) {
			// P
			draw_rect(-88, 0, 2, 12, 0xfffff);
			draw_rect(-84, 10, 6, 2, 0xfffff);
			draw_rect(-78, 6, 2, 6, 0xfffff);
			draw_rect(-84, 2, 6, 2, 0xfffff);
			// R
			draw_rect(-70, 0, 2, 12, 0xfffff);
			draw_rect(-66, 10, 6, 2, 0xfffff);
			draw_rect(-60, 6, 2, 6, 0xfffff);
			draw_rect(-66, 2, 6, 2, 0xfffff);
			draw_rect(-67, 0, 2, 2, 0xfffff);
			draw_rect(-66, -1, 2, 2, 0xfffff);
			draw_rect(-65, -2, 2, 2, 0xfffff);
			draw_rect(-64, -3, 2, 2, 0xfffff);
			draw_rect(-63, -4, 2, 2, 0xfffff);
			draw_rect(-62, -5, 2, 2, 0xfffff);
			draw_rect(-61, -6, 2, 2, 0xfffff);
			draw_rect(-60, -7, 2, 2, 0xfffff);
			draw_rect(-59, -8, 2, 2, 0xfffff);
			draw_rect(-58, -9, 2, 2, 0xfffff);
			draw_rect(-57, -10, 2, 2, 0xfffff);
			// E
			draw_rect(-50, 0, 2, 12, 0xfffff);
			draw_rect(-46, 10, 6, 2, 0xfffff);
			draw_rect(-46, 0, 6, 2, 0xfffff);
			draw_rect(-46, -10, 6, 2, 0xfffff);
			// S
			draw_rect(-30, 10, 6, 2, 0xfffff);
			draw_rect(-34, 5, 2, 6, 0xfffff);
			draw_rect(-30, 0, 6, 2, 0xfffff);
			draw_rect(-26, -6, 2, 6, 0xfffff);
			draw_rect(-30, -10, 6, 2, 0xfffff);
			// S
			draw_rect(-13, 10, 6, 2, 0xfffff);
			draw_rect(-17, 5, 2, 6, 0xfffff);
			draw_rect(-13, 0, 6, 2, 0xfffff);
			draw_rect(-9, -6, 2, 6, 0xfffff);
			draw_rect(-13, -10, 6, 2, 0xfffff);
			// E
			draw_rect(10, 0, 2, 12, 0xfffff);
			draw_rect(14, 10, 6, 2, 0xfffff);
			draw_rect(14, 0, 6, 2, 0xfffff);
			draw_rect(14, -10, 6, 2, 0xfffff);
			// N
			draw_rect(25, 0, 2, 12, 0xfffff);
			draw_rect(26, 10, 2, 2, 0xfffff);
			draw_rect(27, 8, 2, 2, 0xfffff);
			draw_rect(28, 6, 2, 2, 0xfffff);
			draw_rect(29, 4, 2, 2, 0xfffff);
			draw_rect(30, 2, 2, 2, 0xfffff);
			draw_rect(31, 0, 2, 2, 0xfffff);
			draw_rect(32, -2, 2, 2, 0xfffff);
			draw_rect(33, -4, 2, 2, 0xfffff);
			draw_rect(34, -6, 2, 2, 0xfffff);
			draw_rect(35, -8, 2, 2, 0xfffff);
			draw_rect(36, -10, 2, 2, 0xfffff);
			draw_rect(36, 0, 2, 12, 0xfffff);
			// T
			draw_rect(48, 10, 8, 2, 0xfffff);
			draw_rect(48, 0, 2, 12, 0xfffff);
			// E
			draw_rect(60, 0, 2, 12, 0xfffff);
			draw_rect(64, 10, 6, 2, 0xfffff);
			draw_rect(64, 0, 6, 2, 0xfffff);
			draw_rect(64, -10, 6, 2, 0xfffff);
			// R
			draw_rect(74, 0, 2, 12, 0xfffff);
			draw_rect(78, 10, 6, 2, 0xfffff);
			draw_rect(84, 6, 2, 6, 0xfffff);
			draw_rect(78, 2, 6, 2, 0xfffff);
			draw_rect(77, 0, 2, 2, 0xfffff);
			draw_rect(78, -1, 2, 2, 0xfffff);
			draw_rect(79, -2, 2, 2, 0xfffff);
			draw_rect(80, -3, 2, 2, 0xfffff);
			draw_rect(81, -4, 2, 2, 0xfffff);
			draw_rect(82, -5, 2, 2, 0xfffff);
			draw_rect(83, -6, 2, 2, 0xfffff);
			draw_rect(84, -7, 2, 2, 0xfffff);
			draw_rect(85, -8, 2, 2, 0xfffff);
			draw_rect(86, -9, 2, 2, 0xfffff);
			draw_rect(87, -10, 2, 2, 0xfffff);
		}
		else {
			clear_screen(0x000000);
		}
		
	}
	else if (pause == true && start == true) {
		// P
		draw_rect(-58, 0, 2, 12, 0xfffff);
		draw_rect(-54, 10, 6, 2, 0xfffff);
		draw_rect(-48, 6, 2, 6, 0xfffff);
		draw_rect(-54, 2, 6, 2, 0xfffff);
		// R
		draw_rect(-40, 0, 2, 12, 0xfffff);
		draw_rect(-36, 10, 6, 2, 0xfffff);
		draw_rect(-30, 6, 2, 6, 0xfffff);
		draw_rect(-36, 2, 6, 2, 0xfffff);
		draw_rect(-37, 0, 2, 2, 0xfffff);
		draw_rect(-36, -1, 2, 2, 0xfffff);
		draw_rect(-35, -2, 2, 2, 0xfffff);
		draw_rect(-34, -3, 2, 2, 0xfffff);
		draw_rect(-33, -4, 2, 2, 0xfffff);
		draw_rect(-32, -5, 2, 2, 0xfffff);
		draw_rect(-31, -6, 2, 2, 0xfffff);
		draw_rect(-30, -7, 2, 2, 0xfffff);
		draw_rect(-29, -8, 2, 2, 0xfffff);
		draw_rect(-28, -9, 2, 2, 0xfffff);
		draw_rect(-27, -10, 2, 2, 0xfffff);
		// E
		draw_rect(-20, 0, 2, 12, 0xfffff);
		draw_rect(-16, 10, 6, 2, 0xfffff);
		draw_rect(-16, 0, 6, 2, 0xfffff);
		draw_rect(-16, -10, 6, 2, 0xfffff);
		// S
		draw_rect(0, 10, 6, 2, 0xfffff);
		draw_rect(-4, 5, 2, 6, 0xfffff);
		draw_rect(0, 0, 6, 2, 0xfffff);
		draw_rect(4, -6, 2, 6, 0xfffff);
		draw_rect(0, -10, 6, 2, 0xfffff);
		// S
		draw_rect(17, 10, 6, 2, 0xfffff);
		draw_rect(13, 5, 2, 6, 0xfffff);
		draw_rect(17, 0, 6, 2, 0xfffff);
		draw_rect(21, -6, 2, 6, 0xfffff);
		draw_rect(17, -10, 6, 2, 0xfffff);
		// P
		draw_rect(50, 0, 2, 12, 0xfffff);
		draw_rect(54, 10, 6, 2, 0xfffff);
		draw_rect(60, 6, 2, 6, 0xfffff);
		draw_rect(54, 2, 6, 2, 0xfffff);
	}
	
	if (pause == false && start == true) {
		clear_screen(0xff5500);

		float player_1_ddp = 0.f; // acceleration units per second

		if (is_down(BUTTON_UP)) { // movement up
			player_1_ddp += 2000;
		}
		if (is_down(BUTTON_DOWN)) { // movement down
			player_1_ddp -= 2000;
		}

		float player_2_ddp = 0.f; // acceleration units per second

		if (is_down(BUTTON_W)) { // movement up
			player_2_ddp += 2000;
		}
		if (is_down(BUTTON_S)) { // movement down
			player_2_ddp -= 2000;
		}

		simulate_player(&player_1_p, &player_1_dp, player_1_ddp, dt); // player 1

		simulate_player(&player_2_p, &player_2_dp, player_2_ddp, dt); // player 2

		// simulate ball
		{

			ball_p_x = ball_p_x + ball_dp_x * dt; // ball x position equation
			ball_p_y = ball_p_y + ball_dp_y * dt; // ball y position equation

			// ball collision with player 

			if (ball_p_x + ball_half_size > 80 - player_half_size_x &&
				ball_p_x - ball_half_size < 80 + player_half_size_x &&
				ball_p_y + ball_half_size > player_1_p - player_half_size_y &&
				ball_p_y + ball_half_size < player_1_p + player_half_size_y) {
				ball_p_x = 80 - player_half_size_x - ball_half_size;
				ball_dp_x *= -1;
				ball_dp_y = (ball_p_y - player_1_p) * 2 + player_1_dp * .75f;
				color += (int)rand() % INT_MAX;
				ball_dp_x += 5 * -1;
			}

			else if (ball_p_x + ball_half_size > -80 - player_half_size_x &&
				ball_p_x - ball_half_size < -80 + player_half_size_x &&
				ball_p_y + ball_half_size > player_2_p - player_half_size_y &&
				ball_p_y + ball_half_size < player_2_p + player_half_size_y) {
				ball_p_x = -80 + player_half_size_x + ball_half_size;
				ball_dp_x *= -1;
				ball_dp_y = (ball_p_y - player_2_p) * 2 + player_2_dp * .75f;
				color_2 += (int)rand() % INT_MAX;
				ball_dp_x += 5;
			}

			// ball collision with arena top and bottom

			if (ball_p_y + ball_half_size > arena_half_size_y) {
				ball_p_y = arena_half_size_y - ball_half_size;
				ball_dp_y *= -1;
			}
			else if (ball_p_y + ball_half_size - 2 < -arena_half_size_y) {
				ball_p_y = -arena_half_size_y + ball_half_size;
				ball_dp_y *= -1;
			}

			// ball collision with left and right side
			// resets the position of the ball
			// increments the score

			if (ball_p_x + ball_half_size > arena_half_size_x) {
				ball_p_x = arena_half_size_x - ball_half_size;
				ball_p_x = 0;
				ball_p_y = 0;
				ball_dp_x = 100;
				ball_dp_y = 0;
				score_1++;
			}
			else if (ball_p_x + ball_half_size < -arena_half_size_x) {
				ball_p_x = -arena_half_size_x + ball_half_size;
				ball_p_x = 0;
				ball_p_y = 0;
				ball_dp_x = -100;
				ball_dp_y = 0;
				score_2++;
			}
		}

		// Rendering
		draw_rect(0, 0, arena_half_size_x, arena_half_size_y, 0xffaa33); // arena

		draw_rect(ball_p_x, ball_p_y, ball_half_size, ball_half_size, 0xfffffff); // ball

		for (int i = -40; i < 44; i += 5) { // middle line 
			draw_rect(0, i, 1, 1, 0xfffffff);
		}

		draw_rect(80, player_1_p, player_half_size_x, player_half_size_y, color); // player 1
		draw_rect(-80, player_2_p, player_half_size_x, player_half_size_y, color_2); // player 2


		// clock object

		clock_t t;
		t = clock();

		// ball collision with spinners
		if (score_1 >= 3 || score_2 >= 3) {
			if (t / CLOCKS_PER_SEC % 1 >= 0 && t / CLOCKS_PER_SEC % 2 <= 0.5) {
				spinner_state_1_teleporter();
				draw_rect(40, -30, 2.5, 8, 0x702963); // spinner_1 state 1
				draw_rect(-40, 30, 2.5, 8, 0x702963); // spinner_2 state 1
			}
			else {
				spinner_state_2_teleporter();
				draw_rect(40, -30, 8, 2.5, 0x702963); // spinner_1 state 2
				draw_rect(-40, 30, 8, 2.5, 0x702963); // spinner_2 state 2
			}
		}
		else {
			if (t / CLOCKS_PER_SEC % 1 >= 0 && t / CLOCKS_PER_SEC % 2 <= 0.5) {
				spinner_state_1_collision();
				draw_rect(40, -30, 2.5, 8, 0xff0000); // spinner_1 state 1
				draw_rect(-40, 30, 2.5, 8, 0xff0000); // spinner_2 state 1
			}
			else {
				spinner_state_2_collision();
				draw_rect(40, -30, 8, 2.5, 0xff0000); // spinner_1 state 2
				draw_rect(-40, 30, 8, 2.5, 0xff0000); // spinner_2 state 2
			}
		}


		simulate_game_score();

		simulate_score();

		if ((ball_dp_x < 50 && ball_dp_x > 0) || (ball_dp_x > -50 && ball_dp_x < 0)) {
			ball_dp_x = 50;
		}

		if (is_down(BUTTON_Q)) {
			ball_dp_x += 10;
		}

		// game end case
		// resets score
		// resets paddle and ball position

		if (score_1 == 5 || score_2 == 5) {
			simulate_score();
			player_1_p = 0;
			player_2_p = 0;
			player_1_dp = 0;
			player_2_dp = 0;
			player_1_ddp = 0;
			player_2_ddp = 0;
		}

		if (game_score_1 == 5 || game_score_2 == 5) {
			game_score_1 = 0;
			game_score_2 = 0;
			simulate_game_score();
			exit(0);
		}
	}
	if (released(BUTTON_P)) {
		if (pause) {
			pause = false;
		}
		else {
			pause = true;
		}
	}

	if (pressed(BUTTON_ENTER)) {
		start = true;
	}
}