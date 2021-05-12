#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "cards.h"


void assert_card_valid(card_t c)
{
  assert(c.value>=2 && c.value<=14);
  assert(c.suit>=SPADES &&c.suit <= CLUBS);
}

const char * ranking_to_string(hand_ranking_t r)
{
  switch(r)
    {
    case STRAIGHT_FLUSH :
      return "STRAIGHT_FLUSH";
    case FOUR_OF_A_KIND:
      return "FOUR_OF_A_KIND";
    case FULL_HOUSE:
      return "FULL_HOUSE";
    case FLUSH:
      return "FLUSH";
    case STRAIGHT:
      return "STRAIGHT";
    case THREE_OF_A_KIND:
      return "THREE_OF_A_KIND";
    case TWO_PAIR:
      return"TWO_PAIR";
    case PAIR:
      return "PAIR";
    default:
        return "NOTHING";
    }
}

char value_letter(card_t c)
{
  switch(c.value)
    {
    case 2:
            return '2';
    case 3:
            return '3';
    case 4:
            return '4';
    case 5:
            return '5';
    case 6:
            return '6';
    case 7:
            return '7';
    case 8:
            return '8';
    case 9:
      return '9';
    case 10:
      return '0';
    case 11:
      return 'J';
    case 12:
      return 'Q';
    case 13:
      return 'K';
    case 14:
      return 'A';
    default:
      return '?';
    }
}


char suit_letter(card_t c)
{
  switch(c.suit)
    {
    case SPADES:
      return 's';
    case HEARTS:
      return 'h';
    case DIAMONDS:
      return 'd';
    case CLUBS:
      return 'c';
    default:
      return '?';
    }
}

void print_card(card_t c)
{
  printf("%c%c ",value_letter(c),suit_letter(c));
}

card_t card_from_letters(char value_let, char suit_let)
{
  card_t temp;

  temp.value=99;
  temp.suit=NUM_SUITS;
  static const char* value_letters ="234567890JQKA";
  static const char* suit_letters = "shdc";
  int i;
  for(i=0;i<13;++i)
    {
      if(value_letters[i]==value_let)
	{
	  temp.value =i+2;
	  break;
	}
    }
  if(temp.value==99)
    {
      printf("Invalid value letter: %c\n",value_let);
      exit(EXIT_FAILURE);
    }

  for(i=0;i<4;++i)
    {
      if(suit_letters[i]==suit_let)
	{
	  temp.suit=i;
	  break;
	}
    }
  if(temp.suit==NUM_SUITS)
    {
      printf("Invalid suit letter: %c\n",suit_let);
      exit(EXIT_FAILURE);
    }
  /*  if(value_let>=2 && value_let<=14)
    {
      temp.value=value_let;
    }
  if(suit_let=='s' ||suit_let=='h'||suit_let=='d'||suit_let=='c')
      {
	temp.suit=suit_let;
      }
  if(temp.value==-1 ||temp.suit==4)
    {
      printf("Invalid input");
      exit(EXIT_FAILURE);
      }*/
  return temp;
}

card_t card_from_num(unsigned c)
{
  card_t temp;
  temp.suit = c/13;
  temp.value = c%13 + 2;
  return temp;
}
