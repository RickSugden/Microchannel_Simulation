%animation_specProj
%drawing the confined microchannel
close all
clear

NUMBER_OF_FRAME_FILES = 5;

compiled_left_shear = 0;
compiled_right_shear = 0;

cd 'C:\Users\rickj\Desktop\specProj\shearclean\params\d0.7850\a0.50';
header = textread('params.1106','%s','delimiter','\n','whitespace','');%replace the ### after params with ic
header_length = length(header);


cd C:\Users\rickj\Desktop\specProj\shearclean;

for i = 1:NUMBER_OF_FRAME_FILES
    
    file_num = 0;
    file_num = i;
    file_num = num2str(file_num);
    filename = ['frame_output 12345',' ',file_num];
    data =load(filename);
    data_length = length(data);

    %String[] splited = str.split("\\s+");


    x= data(:,1);
    y = data(:,2);
    vx = data(:,3);
    vy= data(:,4);
    ax = data(:,5);
    ay = data(:,6);
    bx= data(:,7);
    by = data(:,8);
    cx = data(:,9);
    cy= data(:,10);
    lxwall_offset= data(:,11);
    rxwall_offset = data(:,12);
    r = data(:,13);
    m = data(:,14);
    invm = data(:,15);
    axp =data(:,16);
    ayp =data(:,17);
    cell=data(:,18);
    next=data(:,19);
    numincell=data(:,20);
    firstincell=data(:,21);

    %find the smallest and largest radii and calculate the wall ball radius
    %the ratio can later be made so its extracted from params
    small_r = min(r(:));
    big_r = max(r(:));
    wall_ball_r = small_r*0.8;

    LX = 50*small_r;
    aspect_ratio = 2;
    LY = aspect_ratio*LX;

    figure
    for j= 1:length(x)
        pos = [(x(j)-r(j)) (y(j)-r(j)) 2*r(j) 2*r(j)]; 
        rectangle('Position',pos,'Curvature',[1 1])

    end  
    frame_position = [0 0 LX LY];

    rectangle('Position',frame_position);

    for j= 0:(2.5*small_r):LY

        pos = [(-wall_ball_r) j 2*wall_ball_r 2*wall_ball_r]; 
        rectangle('Position',pos,'Curvature',[1 1])

        pos = [(LX-wall_ball_r) j 2*wall_ball_r 2*wall_ball_r]; 
        rectangle('Position',pos,'Curvature',[1 1])

    end

    title(strcat('Carbopol Microchannel Simulation restart file',file_num));
    axis ([0 100 0 100]);

    left_wall_list =[];
    right_wall_list = [];

    for wall_cursor = 0:(2.5*small_r):LY %this loop is for the left wall
        %distance to every ball

        for j = 1:length(x) % j will iterate through particle number
            %calculates distance from centre of circles to each left wall ball
            %centre
            distance_to_left = sqrt((x(j))^2+(wall_cursor+wall_ball_r-y(j))^2); 

            if distance_to_left <(wall_ball_r+r(j))%if this is true, they overlap
                left_wall_list = [left_wall_list,j]; %append to the list     
            end

            %repeat for the right side wall
            distance_to_right = sqrt(LX-(x(j))^2+(wall_cursor+wall_ball_r-y(j))^2); 

            if distance_to_right <(wall_ball_r+r(j))%if this is true, they overlap
                right_wall_list = [right_wall_list,j];     
            end

        end
    end

    left_wall_normal_force_list = ax(left_wall_list);
    right_wall_normal_force_list = ax(right_wall_list);

    left_wall_normal_force = sum(left_wall_normal_force_list);
    right_wall_normal_force = sum(right_wall_normal_force_list);

    left_wall_shear_force_list = ay(left_wall_list);
    right_wall_shear_force_list = ay(right_wall_list);

    left_wall_shear_force = sum(left_wall_shear_force_list);
    right_wall_shear_force = sum(right_wall_shear_force_list);


    %fprintf("the normal force on the left wall is %d Newtons \n",left_wall_normal_force); 
    %fprintf("the normal force on the right wall is %d Newtons \n",right_wall_normal_force); 

    fprintf("the shear force on the left wall is %d Newtons \n",left_wall_shear_force); 
    fprintf("the shear force on the right wall is %d Newtons \n",right_wall_shear_force); 
    
    compiled_left_shear(i)= left_wall_shear_force;
    compiled_right_shear(i)= right_wall_shear_force;
end


%plot the shear force vs target density
figure
x = [0.4 0.5 0.6 0.7 0.785 0.8 0.45 0.55 0.475]; %other values threw errors 

subplot(1,2,1);
y = compiled_left_shear;
[x_sorted, x_order] = sort(x);
newy = y(x_order);
plot(x_sorted,newy);
title('Left Wall Shear Force vs Target Density');

subplot(1,2,2);
y = compiled_right_shear;
[x_sorted, x_order] = sort(x);
newy = y(x_order);
plot(x_sorted,newy);
title('Right Wall Shear Force vs Target Density');
