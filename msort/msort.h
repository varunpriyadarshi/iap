/*
 * =====================================================================================
 *
 *       Filename:  msort.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16.08.2015 14:10:33
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Romel J. Torres (rtorres), torres.romel@gmail.com
 *   Organization:  -
 *
 * =====================================================================================
 */

typedef enum m_mode_t {MSORT_UP,MSORT_DOWN} m_mode_t;
void msort (int32_t *src, uint32_t start, uint32_t finish, m_mode_t mode);
void merge (int32_t *src, uint32_t p, uint32_t q, uint32_t r, m_mode_t mode);
