%% modelo de rede neural para calcular percentual de gordura do corpo


%% carrega o dataSet
[X,T] = bodyfat_dataset;
size(X)
size(T)

setdemorandstream(491218382)

%%criando a rede neural

hiddenLayer1Size = 4;
hiddenLayer2Size = 4;
net = fitnet([hiddenLayer1Size hiddenLayer2Size]);
%%net = patternnet( [hiddenLayer1Size hiddenLayer2Size] );
%%net = fitnet(10);
view(net)


%% treinando a rede

[net,tr] = train(net,X,T);
nntraintool

%%ver performace
plotperform(tr)

%%teste do modelo 
testX = X(:,tr.testInd);
testT = T(:,tr.testInd);

testY = net(testX);

perf = mse(net,testT,testY)


%%gráfico de regreção
Y = net(X);

plotregression(T,Y)

%%histrograma
e = T - Y;

ploterrhist(e)

%%matriz de confusão
plotconfusion(testT,testY)

[c,cm] = confusion(testT,testY)

fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));

fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);

%%grafico ROC
plotroc(testT,testY)