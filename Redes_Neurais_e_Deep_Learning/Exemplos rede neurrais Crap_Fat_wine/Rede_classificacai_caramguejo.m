%%rede neural para classificac�o de sexo de caranguejos

%%pega os dados do dataSet
[x,t] = crab_dataset;
size(x)
size(t)
setdemorandstream(491218382)

%%cria a rede neural com um numero n de neuroneos

hiddenLayer1Size = 4;
hiddenLayer2Size = 4;
%%net = fitnet([hiddenLayer1Size hiddenLayer2Size]);
net = patternnet( [hiddenLayer1Size hiddenLayer2Size] );

view(net)

%%ttreina a rede utilizandos os dados do dataSet
[net,tr] = train(net,x,t);
nntraintool


%%mostra um gr�fico com a performance da rede
plotperform(tr)



%%testa a rede com a parte do data set resevado para treino
testX = x(:,tr.testInd);
testT = t(:,tr.testInd);

testY = net(testX);
testIndices = vec2ind(testY)


%%plota a matriz de confus�o para os testes realizados
plotconfusion(testT,testY)


[c,cm] = confusion(testT,testY)

fprintf('Percentage Correct Classification   : %f%%\n', 100*(1-c));
fprintf('Percentage Incorrect Classification : %f%%\n', 100*c);

%%plota o gr�fico ROC
plotroc(testT,testY)

