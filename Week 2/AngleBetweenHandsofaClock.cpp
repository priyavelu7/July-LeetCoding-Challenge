/*
Given two numbers, hour and minutes. Return the smaller angle (in degrees) formed between the hour and the minute hand.
*/
class Solution {
public:
double angleClock(int hour, int minutes) {
  double minangle=(minutes)*(360/60.0);
  double hourangle=(hour*60+minutes)*(360/(12.0*60));
  double angle=abs(minangle-hourangle);
  return min(angle,360-angle);
}
};
