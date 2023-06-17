int size = 0;
int string_contains(char* s, int sSize, char p)
{
  for(int i=0; i < sSize; i++)
    {
      if(s[i] == p)
        return 1;
    }
  return 0;
}
int lengthOfLongestSubstring(char* s)
{
  size = strlen(s);
  if(size <= 1)
    return size;
  int maxSize = size;
  if(size > 95)
    maxSize = 95;
  int lastSize = 0;
  char* newS = malloc(sizeof(*newS)*size);
  int c = 0;
  for(int i=0; i < size; i++)
    {
      if(size-i < lastSize)
        break;
      for(int j=i; j < size; j++)
        {
	  if(string_contains(newS, c, s[j]))
	  {
	    if(c > lastSize)
	      lastSize = c;
	    c = 0;
	    break;
	  }
	  else
            {
	      newS[c] = s[j];
	      c++;
	      if(c == size || c == maxSize)
                return c;
            }
        }
    }
  free(newS);
  return lastSize;
}
