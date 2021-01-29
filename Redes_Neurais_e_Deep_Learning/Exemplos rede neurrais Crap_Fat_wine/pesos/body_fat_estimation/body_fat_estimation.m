[X,T] = bodyfat_dataset;

size(X)
size(T)

setdemorandstream(491218382)

net = fitnet(15);
view(net)


[net,tr] = train(net,X,T);


nntraintool

figure();
plotperform(tr)


testX = X(:,tr.testInd);
testT = T(:,tr.testInd);

testY = net(testX);

perf = mse(net,testT,testY)



Y = net(X);


figure();
plotregression(T,Y)



e = T - Y;

figure();
ploterrhist(e)