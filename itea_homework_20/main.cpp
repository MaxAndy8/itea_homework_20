#include <iostream>
#include <Windows.h>

class ChessPiece {
public:
    ChessPiece() : symbol(L' ') {}
    explicit ChessPiece(wchar_t symbol) : symbol(symbol) {}

    friend std::wostream& operator<<(std::wostream& os, const ChessPiece& piece) {
        os << piece.symbol;
        return os;
    }

private:
    wchar_t symbol;
};

class ChessBoard {
public:
    ChessBoard() {
        // Ініціалізуємо фігури на дошці (в цьому прикладі лише символи для розташування)
        // Ваша логіка розташування фігур може відрізнятися
        for (int i = 0; i < 8; i++) {
            board[1][i] = ChessPiece(L'п'); // Пішаки білі
            board[6][i] = ChessPiece(L'p'); // Пішаки чорні
        }

        board[0][0] = board[0][7] = ChessPiece(L'Т'); // Білі тури
        board[7][0] = board[7][7] = ChessPiece(L'T'); // Чорні тури

        board[0][1] = board[0][6] = ChessPiece(L'К'); // Білі коні
        board[7][1] = board[7][6] = ChessPiece(L'H'); // Чорні коні

        board[0][2] = board[0][5] = ChessPiece(L'С'); // Білі слони
        board[7][2] = board[7][5] = ChessPiece(L'E'); // Чорні слони

        board[0][3] = ChessPiece(L'Ф'); // Білий ферзь
        board[7][3] = ChessPiece(L'Q'); // Чорний ферзь

        board[0][4] = ChessPiece(L'М'); // Білий король
        board[7][4] = ChessPiece(L'K'); // Чорний король
    }

    // Виводимо шахову дошку
    void printBoard(bool isWhitePerspective) {

        std::wcout << L' ';
        for (size_t i = 0; i < 8; i++) {
            std::wcout << horizontal_headings[isWhitePerspective ? i : 7 - i];
        }
        std::wcout << L' ' << std::endl;
        
        for (int i = isWhitePerspective ? 7 : 0; isWhitePerspective ? i >= 0 : i < 8; isWhitePerspective ? i-- : i++) {
            
            std::wcout << vertical_headings[i];
            for (int j = isWhitePerspective ? 7 : 0; isWhitePerspective ? j >= 0 : j < 8; isWhitePerspective ? j-- : j++) {
                std::wcout << board[i][j];
            }
            std::wcout << vertical_headings[i] << std::endl;           
        }

        std::wcout << L' ';
        for (size_t i = 0; i < 8; i++) {
            std::wcout << horizontal_headings[isWhitePerspective ? i : 7 - i];
        }
        std::wcout << L' ' << std::endl;
    }

private:
    ChessPiece board[8][8];

    static const wchar_t horizontal_headings[8];
    static const wchar_t vertical_headings[8];
};

const wchar_t ChessBoard::horizontal_headings[8] = { L'a', L'b', L'c', L'd', L'e', L'f', L'g', L'h' };
const wchar_t ChessBoard::vertical_headings[8]   = { L'1', L'2', L'3', L'4', L'5', L'6', L'7', L'8' };

int main() {
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 
    setlocale(LC_ALL, "");

    ChessBoard chessBoard;

    // Виводимо дошку з погляду білих
    std::wcout << L"Дошка з погляду білих:" << std::endl;
    chessBoard.printBoard(true);

    std::cout << std::endl;

    // Виводимо дошку з погляду чорних
    std::wcout << L"Дошка з погляду чорних:" << std::endl;
    chessBoard.printBoard(false);

    return 0;
}
