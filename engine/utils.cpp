#include "utils.h"
#include "board.h"
#include "limits"
#include <bits/stdc++.h>

std::string format::eval() {
    double divided_score = static_cast<double>(board::current_eval) / 100.0;
    std::string formatted_score = std::to_string(divided_score);
    size_t dotPosition = formatted_score.find('.');
    
    // Ensure there are exactly two decimal places
    if (dotPosition != std::string::npos && dotPosition + 3 < formatted_score.length()) {
        formatted_score = formatted_score.substr(0, dotPosition + 3);
    }
    
    return formatted_score;
}

std::string format::move(int move) {
    return index_to_square[get_source(move)] +
           index_to_square[get_target(move)] + 
           char(promoted_pieces[get_promotion_piece_type(move)]);
}

void print::move(int move) {
    cout << format::move(move);
}

void print::all_moves(moves *move_list) {

    if(!move_list->size) {
        cout << "\n     No moves in move list!";
        return;
    }

    cout << "\n     move    piece   capture   double    en passant    castling    score\n\n";

    for (int move_count = 0; move_count < move_list->size; move_count++)
    {
        int move = move_list->array[move_count];
        
        cout << "     " << index_to_square[get_source(move)] <<
        index_to_square[get_target(move)] <<
        char(promoted_pieces[get_promotion_piece_type(move)]) <<
        "   " << ascii_pieces[get_piece(move)] << 
        "       " << (is_capture(move) ? 1 : 0) <<
        "         " << (is_double_pawn_push(move) ? 1 : 0) <<
        "         " << (is_en_passant(move) ? 1 : 0) << 
        "             " << (is_castling(move) ? 1 : 0) << 
        "           " << (board::score_move(move)) << endl;
    }
    
    cout << "\n     Total number of moves: " << move_list->size << "\n\n";
}

void print::attacked_squares(int side) {
    U64 result = 0ULL;
    for (int square = 0; square < 64; square++)
    {
        if(board::is_square_attacked(square, side)) set_bit(result, square);
    }
    
    print::bitboard(result);
}


void print::bitboard(U64 bitboard)
{
    int square;
    cout << "\n";

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            square = rank * 8 + file;

            if (!file)
                cout << "  " << 8 - rank << " ";

            cout << " " << get_bit(bitboard, square);
        }

        cout << "\n";
    }

    cout << "\n     a b c d e f g h\n\n";

    cout << "     bitboard: " << bitboard << "\n";
}

void print::game() {
    int square;
    cout << "\n";

    for (int rank = 0; rank < 8; rank++)
    {
        for (int file = 0; file < 8; file++)
        {
            square = rank * 8 + file;

            if (!file)
                cout << "  " << 8 - rank << " ";

            int piece = -1;
            for(int i = 0; i < 12; i++) {
                if(is_occupied(board::bitboards[i], square)) {
                    piece = i;
                    break;
                }
            }

            cout << " " << (piece == -1 ? "." : ascii_pieces[piece]);

        }

        cout << "\n";
    }

    cout << "\n     a b c d e f g h\n\n";
    cout << "     Side:        " << (board::side == white ? "white" : "black") << endl;
    cout << "     en_passant:  " << ((board::en_passant != no_sq) ? index_to_square[board::en_passant] : "no") << endl;
    cout << "     Castling:    " << ((board::castle & wk) ? 'K' : '-') <<
                                    ((board::castle & wq) ? 'Q' : '-') <<
                                    ((board::castle & bk) ? 'k' : '-') <<
                                    ((board::castle & bq) ? 'q' : '-') <<
                                    endl;
}

Timer::Timer() {
    start_time = std::chrono::high_resolution_clock::now();
}

void Timer::reset() {
    start_time = std::chrono::high_resolution_clock::now();
}

double Timer::get_time_passed_millis() {
    auto current_time = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(current_time - start_time).count();
}

Timer timer;

bool stop_calculating = false;
bool use_time = false;
double stop_time = std::numeric_limits<double>::infinity();
