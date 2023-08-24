#include "shorthands.h"

// Shorthand for getting the index of a square from its name
const char *index_to_square[] = {
    "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8",
    "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
    "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
    "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
    "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
    "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
    "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
    "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1"};

// ASCII pieces
const char ascii_pieces[] = "PNBRQKpnbrqk";

// Unicode pieces (can't be printed to windows console)
const char *unicode_pieces[12] = {"♙", "♘", "♗", "♖", "♕", "♔", "♟︎", "♞", "♝", "♜", "♛", "♚"};

map<char, int> char_pieces = {
    {'P', P},
    {'N', N},
    {'B', B},
    {'R', R},
    {'Q', Q},
    {'K', K},
    {'p', p},
    {'n', n},
    {'b', b},
    {'r', r},
    {'q', q},
    {'k', k}};

map<char, int> promoted_pieces = {
    {Q, 'q'},
    {R, 'r'},
    {B, 'b'},
    {N, 'n'},
    {q, 'q'},
    {r, 'r'},
    {b, 'b'},
    {n, 'n'},
    {0, ' '}};

// FEN dedug positions
string empty_board = "8/8/8/8/8/8/8/8 w - - ";
string start_position = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
string pawns_position = "8/pppppppp/8/8/8/8/PPPPPPPP/8 w KQkq - 0 1 ";
string tricky_position = "r3k2r/p1ppqpb1/bn2pnp1/3PN3/1p2P3/2N2Q1p/PPPBBPPP/R3K2R w KQkq - 0 1 ";
string killer_position = "rnbqkb1r/pp1p1pPp/8/2p1pP2/1P1P4/3P3P/P1P1P3/RNBQKBNR w KQkq e6 0 1";
string cmk_position = "r2q1rk1/ppp2ppp/2n1bn2/2b1p3/3pP3/3P1NPP/PPP1NPB1/R1BQ1RK1 b - -";
string rook_position = "8/2p5/3p4/KP5r/1R3p1k/8/4P1P1/8 w - - ";

const int P_score[64] = 
{
    190, 190, 190, 190, 190, 190, 190, 190, 
    130, 130, 130, 140, 140, 130, 130, 130,
    120, 120, 120, 130, 130, 130, 120, 120,
    110, 110, 110, 120, 120, 110, 110, 110,
    105, 105, 110, 120, 120, 105, 105, 105,
    100, 100, 100, 105, 105, 100, 100, 100, 
    100, 100, 100, 90,  90,  100, 100, 100,
    100, 100, 100, 100, 100, 100, 100, 100
};

const int N_score[64] = 
{
    295, 300, 300, 300, 300, 300, 300, 295, 
    295, 300, 300, 310, 310, 300, 300, 295,
    295, 305, 320, 320, 320, 320, 305, 295,
    295, 310, 320, 330, 330, 320, 310, 295,
    295, 310, 320, 330, 330, 320, 310, 295,
    295, 305, 320, 310, 310, 320, 305, 295,
    295, 300, 300, 300, 300, 300, 300, 295,
    295, 290, 300, 300, 300, 300, 290, 295
};

const int B_score[64] = 
{
    320, 320, 320, 320, 320, 320, 320, 320, 
    320, 320, 320, 320, 320, 320, 320, 320,
    320, 320, 320, 330, 330, 320, 320, 320,
    320, 320, 330, 340, 340, 330, 320, 320,
    320, 320, 330, 340, 340, 330, 320, 320, 
    320, 330, 320, 320, 320, 320, 330, 320,
    320, 350, 320, 320, 320, 320, 350, 320,
    320, 320, 310, 320, 320, 310, 320, 320
};

const int R_score[64] =
{
    550, 550, 550, 550, 550, 550, 550, 550, 
    550, 550, 550, 550, 550, 550, 550, 550,
    500, 500, 510, 520, 520, 510, 500, 500,
    500, 500, 510, 520, 520, 510, 500, 500,
    500, 500, 510, 520, 520, 510, 500, 500,
    500, 500, 510, 520, 520, 510, 500, 500,
    500, 500, 510, 520, 520, 510, 500, 500,
    500, 500, 500, 520, 520, 500, 500, 500
};

const int Q_score[64] = 
{
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
    1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000
};

const int K_score[64] = 
{
    10000, 10000, 10000, 10000, 10000, 10000, 10000, 10000, 
    10000, 10000, 10005, 10005, 10005, 10005, 10000, 10000,
    10000, 10005, 10005, 10010, 10010, 10005, 10005, 10000,
    10000, 10005, 10010, 10020, 10020, 10010, 10005, 10000,
    10000, 10005, 10010, 10020, 10020, 10010, 10005, 10000,
    10000, 10000, 10005, 10010, 10010, 10005, 10000, 10000,
    10000, 10005, 10005, 9995, 9995, 10000, 10005, 10000,
    10000, 10000, 10005, 10000, 9985, 10000, 10010, 10000
};

const int p_score[64] = 
{
    -100, -100, -100, -100, -100, -100, -100, -100, 
    -100, -100, -100,  -90,  -90, -100, -100, -100,
    -100, -100, -100, -105, -105, -100, -100, -100,
    -105, -105, -110, -120, -120, -105, -105, -105,
    -110, -110, -110, -120, -120, -110, -110, -110,
    -120, -120, -120, -130, -130, -130, -120, -120,
    -130, -130, -130, -140, -140, -130, -130, -130,
    -190, -190, -190, -190, -190, -190, -190, -190
};

const int n_score[64] = 
{
    -295, -290, -300, -300, -300, -300, -290, -295, 
    -295, -300, -300, -300, -300, -300, -300, -295,
    -295, -305, -320, -310, -310, -320, -305, -295,
    -295, -310, -320, -330, -330, -320, -310, -295,
    -295, -310, -320, -330, -330, -320, -310, -295,
    -295, -305, -320, -320, -320, -320, -305, -295,
    -295, -300, -300, -310, -310, -300, -300, -295,
    -295, -300, -300, -300, -300, -300, -300, -295
};

const int b_score[64] = 
{
    -320, -320, -310, -320, -320, -310, -320, -320, 
    -320, -350, -320, -320, -320, -320, -350, -320,
    -320, -330, -320, -320, -320, -320, -330, -320,
    -320, -320, -330, -340, -340, -330, -320, -320,
    -320, -320, -330, -340, -340, -330, -320, -320,
    -320, -320, -320, -330, -330, -320, -320, -320,
    -320, -320, -320, -320, -320, -320, -320, -320,
    -320, -320, -320, -320, -320, -320, -320, -320
};

const int r_score[64] = 
{
    -500, -500, -500, -520, -520, -500, -500, -500, 
    -500, -500, -510, -520, -520, -510, -500, -500,
    -500, -500, -510, -520, -520, -510, -500, -500,
    -500, -500, -510, -520, -520, -510, -500, -500,
    -500, -500, -510, -520, -520, -510, -500, -500,
    -500, -500, -510, -520, -520, -510, -500, -500, 
    -550, -550, -550, -550, -550, -550, -550, -550,
    -550, -550, -550, -550, -550, -550, -550, -550
};

const int q_score[64] = 
{
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000, 
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000,
    -1000, -1000, -1000, -1000, -1000, -1000, -1000, -1000
};

const int k_score[64] = 
{
    -10000, -10000, -10005, -10000, -9985, -10000, -10010, -10000, 
    -10000, -10005, -10005, -9995, -9995, -10000, -10005, -10000,
    -10000, -10000, -10005, -10010, -10010, -10005, -10000, -10000,
    -10000, -10005, -10010, -10020, -10020, -10010, -10005, -10000,
    -10000, -10005, -10010, -10020, -10020, -10010, -10005, -10000,
    -10000, -10005, -10005, -10010, -10010, -10005, -10005, -10000,
    -10000, -10000, -10005, -10005, -10005, -10005, -10000, -10000,
    -10000, -10000, -10000, -10000, -10000, -10000, -10000, -10000
};

const int* piece_score[] = {
    P_score, N_score, B_score, R_score, Q_score, K_score,
    p_score, n_score, b_score, r_score, q_score, k_score
};

// MVV LVA [attacker][victim]
const int mvv_lva[12][12] = {
 	105, 205, 305, 405, 505, 605,  105, 205, 305, 405, 505, 605,
	104, 204, 304, 404, 504, 604,  104, 204, 304, 404, 504, 604,
	103, 203, 303, 403, 503, 603,  103, 203, 303, 403, 503, 603,
	102, 202, 302, 402, 502, 602,  102, 202, 302, 402, 502, 602,
	101, 201, 301, 401, 501, 601,  101, 201, 301, 401, 501, 601,
	100, 200, 300, 400, 500, 600,  100, 200, 300, 400, 500, 600,

	105, 205, 305, 405, 505, 605,  105, 205, 305, 405, 505, 605,
	104, 204, 304, 404, 504, 604,  104, 204, 304, 404, 504, 604,
	103, 203, 303, 403, 503, 603,  103, 203, 303, 403, 503, 603,
	102, 202, 302, 402, 502, 602,  102, 202, 302, 402, 502, 602,
	101, 201, 301, 401, 501, 601,  101, 201, 301, 401, 501, 601,
	100, 200, 300, 400, 500, 600,  100, 200, 300, 400, 500, 600
};