from GuiConnection import *



def mainfun():

    start=time.time()     # to calculate  ETA

    main = Algorithm(8)
    selected_condition = condition()
    main.create_initials()

    chromosomes_list = main.get_initials()


    fittest_list_to_draw=[]   # create list with the most fittest chromosomes in each generation

    
    for i in range(0, 10):
        
        main.calculate_fitness(chromosomes_list, selected_condition)


        f=main.the_most_fittest_chromosome()   
        f_percentage=int((f*100)/6)
        fittest_list_to_draw.append(f_percentage)


        if main.fitness_sorted[0][1] == 6:
            
            # calculate the characteristics
            main.fittest_tokens_fun()
            fittest_list=main.get_fittest_tokens()     # list with the characteristics
            print_characteristics(fittest_list)

            # calculate the cost 
            cost = calculate_cost(fittest_list)
            cost_result.setText("             " + str(cost)+" $")


            draw(i+1,fittest_list_to_draw)
            #drawbtn.clicked.connect(lambda :draw(i+1,fit_draw))

            t=(time.time() - start) * 1000   # ETA time 
            time_result.setText("            " + str(int(t))+" ms")
            #print i+1
            gennum_result.setText("              "+str(i+1))
            break



        main.do_crossover()
        main.do_mutation()
        chromosomes_list = main.get_mutated()


        #draw()



startbtn.clicked.connect(mainfun)
drawbtn.clicked.connect(draw_show)


### start GUI
main_gui.show()
Gui_app.exec_()
