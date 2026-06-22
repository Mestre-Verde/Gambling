#if !defined(COLORS_H)
#define COLORS_H

// Reset
#define COLOR_RESET "\033[0m"

// Texto normal
#define COLOR_BLACK "\033[30m"
#define COLOR_RED "\033[31m"
#define COLOR_GREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_WHITE "\033[37m"
#define COLOR_GOLD "\033[38;5;214m"
#define COLOR_AMBER "\033[38;5;220m"
#define COLOR_YELLOW_SOFT "\033[93m"
#define COLOR_ORANGE "\033[38;5;208m"
#define COLOR_GOLD_SOFT "\033[38;5;220m"
#define COLOR_AMBER_SOFT "\033[38;5;214m"
#define COLOR_SAND "\033[38;5;180m"
#define COLOR_SKY_BLUE "\033[38;5;117m"
#define COLOR_DEEP_BLUE "\033[38;5;27m"
#define COLOR_NAVY "\033[38;5;18m"
#define COLOR_PURPLE_SOFT "\033[38;5;141m"
#define COLOR_VIOLET "\033[38;5;135m"
#define COLOR_PINK_SOFT "\033[38;5;218m"
#define COLOR_ROSE "\033[38;5;204m"
#define COLOR_TEAL "\033[38;5;37m"
#define COLOR_SEA_GREEN "\033[38;5;36m"
#define COLOR_GRAY_SOFT "\033[38;5;250m"
#define COLOR_GRAY "\033[38;5;244m"
#define COLOR_GRAY_DARK "\033[38;5;240m"

// Texto brilhante
#define COLOR_BRIGHT_BLACK "\033[90m"
#define COLOR_BRIGHT_RED "\033[91m"
#define COLOR_BRIGHT_GREEN "\033[92m"
#define COLOR_BRIGHT_YELLOW "\033[93m"
#define COLOR_BRIGHT_BLUE "\033[94m"
#define COLOR_BRIGHT_MAGENTA "\033[95m"
#define COLOR_BRIGHT_CYAN "\033[96m"
#define COLOR_BRIGHT_WHITE "\033[97m"

// Fundo
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"

// Estilos
#define TEXT_BOLD "\033[1m"
#define TEXT_DIM "\033[2m"
#define TEXT_ITALIC "\033[3m"
#define TEXT_UNDERLINE "\033[4m"
#define TEXT_BLINK "\033[5m"
#define TEXT_REVERSE "\033[7m"

// Limpar terminal
#define CLEAR_SCREEN "\033[2J"

// Cursor
#define CURSOR_HOME "\033[H"

// Limpar linha atual
#define CLEAR_LINE "\r\033[2K"

#endif // COLORS_H