#include "termcolor-c.h"

#define DEFUN_T(c, code) \
    FILE* text_##c(FILE* stream) { \
        if (supports_color(stream)) { \
            fputs(ANSI_CODE_##code, stream); \
        } \
        return stream; \
    }


DEFUN_T(bold, BOLD);
DEFUN_T(dark, DARK);
DEFUN_T(underline, UNDERLINE);
DEFUN_T(blink, BLINK);
DEFUN_T(reverse, REVERSE);
DEFUN_T(concealed, CONCEALED);
DEFUN_T(gray, GRAY);
DEFUN_T(grey, GREY);
DEFUN_T(red, RED);
DEFUN_T(green, GREEN);
DEFUN_T(yellow, YELLOW);
DEFUN_T(blue, BLUE);
DEFUN_T(magenta, MAGENTA);
DEFUN_T(cyan, CYAN);
DEFUN_T(white, WHITE);
#undef DEFUN_T

#define DEFUN_B(c, code) \
    FILE* background_##c(FILE* stream) { \
        if (supports_color(stream)) { \
            fputs(ANSI_CODE_BG_##code, stream); \
        } \
        return stream; \
    }
DEFUN_B(gray, GRAY);
DEFUN_B(grey, GREY);
DEFUN_B(red, RED);
DEFUN_B(green, GREEN);
DEFUN_B(yellow, YELLOW);
DEFUN_B(blue, BLUE);
DEFUN_B(magenta, MAGENTA);
DEFUN_B(cyan, CYAN);
DEFUN_B(white, WHITE);
#undef DEFUN_B

bool supports_color(FILE *stream)
{
	return isatty(fileno(stream));
}

void reset_colors(FILE* stream) {
    if (supports_color(stream)) {
        fputs(ANSI_CODE_RESET, stream);
    }
}
