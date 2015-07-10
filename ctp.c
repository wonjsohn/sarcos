static int 
change_turing_test_task(void)
{
  int    ivar;
  double dvar;
      
        get_double("Gain Control",gainControl,&dvar);
        if ((dvar >= 0.0) && (dvar <= 2.0))
        {
                gainControl                                          = aux;
        }

  return TRUE;

}

