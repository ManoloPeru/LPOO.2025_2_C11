CREATE TABLE Maintenance (
    MaintenanceId INT IDENTITY(1,1) PRIMARY KEY,
    MachineId INT,
    Type VARCHAR(20),
    Date VARCHAR(10),
    State VARCHAR(10),
    Description VARCHAR(200),
    Cost  DECIMAL(10,2) NULL
);