#include "hwlib.hpp"

// Letters
uint8_t A[8] = {
        0b00011000,0b00100100,0b01000010,0b01000010,
        0b01111110,0b01000010,0b01000010,0b01000010};
uint8_t B[8] = {
        0b01111100,0b01000010,0b01000010,0b01111100,
        0b01000010,0b01000010,0b01000010,0b01111100};
uint8_t C[8] = {
        0b00011100,0b00100010,0b01000000,0b01000000,
        0b01000000,0b01000000,0b00100010,0b00011100};
uint8_t D[8] = {
        0b01111000,0b01000100,0b01000010,0b01000010,
        0b01000010,0b01000010,0b01000100,0b01111000};
uint8_t E[8] = {
        0b01111110,0b01000000,0b01000000,0b01111110,
        0b01000000,0b01000000,0b01000000,0b01111110};
uint8_t F[8] = {
        0b01111110,0b01000000,0b01000000,0b01111110,
        0b01000000,0b01000000,0b01000000,0b01000000};
uint8_t G[8] = {
        0b00011100,0b00100010,0b01000000,0b01000000,
        0b01001110,0b01000010,0b00100010,0b00011110};
uint8_t H[8] = {
        0b01000010,0b01000010,0b01000010,0b01111110,
        0b01000010,0b01000010,0b01000010,0b01000010};
uint8_t I[8] = {
        0b00111000,0b00010000,0b00010000,0b00010000,
        0b00010000,0b00010000,0b00010000,0b00111000};
uint8_t J[8] = {
        0b00001110,0b00000010,0b00000010,0b00000010,
        0b00000010,0b01000010,0b01000100,0b00111000};
uint8_t K[8] = {
        0b01000010,0b01000100,0b01001000,0b01110000,
        0b01110000,0b01001000,0b01000100,0b01000010};
uint8_t L[8] = {
        0b01000000,0b01000000,0b01000000,0b01000000,
        0b01000000,0b01000000,0b01000000,0b01111110};
uint8_t M[8] = {
        0b01000010,0b01100110,0b01011010,0b01000010,
        0b01000010,0b01000010,0b01000010,0b01000010};
uint8_t N[8] = {
        0b01000010,0b01000010,0b01100010,0b01010010,
        0b01001010,0b01000110,0b01000010,0b1000010};
uint8_t O[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01000010,0b01000010,0b00111100};
uint8_t P[8] = {
        0b01111100,0b01000010,0b01000010,0b01111100,
        0b01000000,0b01000000,0b01000000,0b01000000};
uint8_t Q[8] = {
        0b00111100,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01001010,0b01000110,0b00111101};
uint8_t R[8] = {
        0b01111100,0b01000010,0b01000010,0b01111100,
        0b01010000,0b01001000,0b01000100,0b01000010};
uint8_t S[8] = {
        0b00111100,0b01000010,0b01000000,0b00111100,
        0b00000010,0b00000010,0b01000010,0b00111100};
uint8_t T[8] = {
        0b11111110,0b00010000,0b00010000,0b00010000,
        0b00010000,0b00010000,0b00010000,0b00010000};
uint8_t U[8] = {
        0b01000010,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01000010,0b01000010,0b00111100};
uint8_t V[8] = {
        0b01000010,0b01000010,0b01000010,0b01000010,
        0b00100100,0b00100100,0b00011000,0b00011000};
uint8_t W[8] = {
        0b01000010,0b01000010,0b01000010,0b01000010,
        0b01000010,0b01011010,0b01100110,0b01000010};
uint8_t X[8] = {
        0b01000010,0b01000010,0b00100100,0b00011000,
        0b00011000,0b00100100,0b01000010,0b01000010};
uint8_t Y[8] = {
        0b10000010,0b01000100,0b00101000,0b00010000,
        0b00010000,0b00010000,0b00010000,0b00010000};
uint8_t Z[8] = {
        0b01111110,0b00000010,0b00000100,0b00001000,
        0b00010000,0b00100000,0b01000000,0b01111110};
