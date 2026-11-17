#include "raylib.h"

constexpr int SCREEN_WIDTH = 800;
constexpr int SCREEN_HEIGHT = 600;
constexpr float BALL_RADIUS = 15.0f;
constexpr float GRAVITY = 650.0f;
constexpr float x_restitution = 0.999f;
constexpr float y_restitution = 0.55f;

void UpdateBall (float& x, float& y, float& vx, float& vy, float dt) {
    vy += 98.0f * dt;
    vx *= x_restitution;

    x += vx * dt;
    y += vy * dt;
    
    // Y collision
    if (y >= SCREEN_HEIGHT - BALL_RADIUS) {
        y = SCREEN_HEIGHT - BALL_RADIUS;

        vy *= -1 * y_restitution;
    };
    if (y <= BALL_RADIUS) {
        y = BALL_RADIUS;

        vy *= -1 * y_restitution;
    };

    // X collision
    if (x >= SCREEN_WIDTH - BALL_RADIUS) {
        x = SCREEN_WIDTH - BALL_RADIUS;

        vx *= -1 * x_restitution;
    };
    if (x <= BALL_RADIUS) {
        x = BALL_RADIUS;

        vx *= -1 * x_restitution;
    };

    if (IsKeyPressed(KEY_SPACE)) {
        vy = -100.0f;
    }

    if (IsKeyPressed(KEY_R)) {
        x = SCREEN_WIDTH / 2.0f;
        y = SCREEN_HEIGHT / 2.0f;
        vx = -260.0f;
        vy = 0.0f;
    }

    constexpr float THRUST = 500.0f;

    if (IsKeyDown(KEY_RIGHT)) {
        vx += THRUST * dt;
    }
    if (IsKeyDown(KEY_LEFT)) {
        vx -= THRUST * dt;
    }
}

void DrawBall(float x, float y, float vx, float vy) {
    ClearBackground(BLACK);
    DrawCircle(x, (int)y, 15, RAYWHITE);
}

int main() {
    InitWindow(800, 600, "2D Lander");
    SetTargetFPS(60);

    float x = SCREEN_WIDTH / 2.0f;
    float y = SCREEN_HEIGHT / 2.0f;
    float vx = -200.0f;
    float vy = 0.0f;

    while (!WindowShouldClose()) {
        float dt = GetFrameTime();
        UpdateBall(x, y, vx, vy, dt);

        BeginDrawing();
        DrawText(TextFormat("Pos: (%.1f, %.1f)", x, y), 15, 15, 20, LIGHTGRAY);
        DrawText(TextFormat("Vel: (%.1f, %.1f)", vx, vy), 15, 40, 20, LIGHTGRAY);
        DrawText("SPACE: Jump | ARROWS: Push | R: Reset", 15, SCREEN_HEIGHT - 30, 18, DARKGRAY);
        EndDrawing();

        DrawBall(x, y, vx, vy);
    }

    CloseWindow();
    return 0;
}