#ifndef BUTTON_H_
#define BUTTON_H_

#include "raylib.h"

class Button {
    private:
        Texture2D text;
        Vector2 pos;
    public:
        Button(const char* path, Vector2 _pos, float scale) {
            pos = _pos;

            Image img = LoadImage(path);

            int orginal_width = img.width;
            int orginal_height = img.height;

            int new_width = orginal_width * scale;
            int new_height = orginal_height * scale;

            ImageResize(&img, new_width, new_height);

            text = LoadTextureFromImage(img);
            
            UnloadImage(img);
        }

        void Draw() {
            DrawTexture(text, pos.x, pos.y, WHITE);
        }
};

#endif // !BUTTON_H_