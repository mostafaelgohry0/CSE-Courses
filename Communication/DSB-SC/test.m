
                 %%%%%%%%%%  message  amd carray  ploting    in differante domains
                        
                        
fm=100;                                                              %  message frequency 
fc=1000;                                                           %  carray frequency 


st_cos=1/(100*fc) ;                                                    %  sample rate  of cos 
t_cos=-20/fc:st_cos:20/fc;                                            %  time of cos 


st_sinc= 1/(10*fm) ;                                                    %  sample rate  of sinc
t_sinc=-1/fm:st_sinc:1/fm;                                              %  time of sinc



m=3*sinc(2*pi*t_sinc*fm);                                   %the message   signal  at time 
c=3*cos(2*pi*t_cos*fc);                                     %the carray   signal   at time

%f_sinc=linspace(-fm/2,fm/2,length(t_sinc))                   % frequency of sinc 
m_freq=fftshift(fft(m));                                      %  sinc in frequency domain

%f_cos=linspace(-fc/2,fc/2,length(t_cos));                      % frequency of cos
c_freq=fftshift(fft(c));                                        %  cos in frequency domain


% ploting  the message  signal    "sinc" 
figure
subplot(2,1,1);plot(t_sinc,m);title ("message in time domain \"sinc \" "); grid on ;   
subplot(2,1,2);plot(abs(m_freq));title ("message in frequency domain  \"sinc \" "); grid on ;

% ploting  the carray signal    "cos"
figure;;
subplot(2,1,1);plot(t_cos,c);title ("carray  in time domain \"cos \" "); grid on ;
subplot(2,1,2);plot(abs(c_freq));title ("carray in frequency domain  \"cos\" "); grid on ;




