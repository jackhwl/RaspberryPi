void setTimeBuffer(char *buffer, unsigned long seconds, bool withHour)
{
    uint8_t hours, minutes;
    minutes = seconds / 60;
    hours = minutes / 60;
    if (withHour)
        sprintf(buffer, "%02u:%02u:%02u", hours, minutes % 60, seconds % 60);
    else
        sprintf(buffer, "%02u:%02u", minutes, seconds % 60);
}
